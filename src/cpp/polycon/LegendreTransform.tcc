#pragma once

#include <PowerDiagram/support/operators/argmax.h>
#include <PowerDiagram/support/operators/norm_2.h>
#include <PowerDiagram/support/operators/abs.h>
#include <PowerDiagram/support/operators/all.h>
#include <PowerDiagram/support/operators/sp.h>
#include <PowerDiagram/support/ASSERT.h>
#include "LegendreTransform.h"
#include <eigen3/Eigen/LU>
#include "PolyCon.h"

#define DTP template<class Scalar,int nb_dims>
#define UTP LegendreTransform<Scalar,nb_dims>

DTP UTP::LegendreTransform( PolyCon<Scalar,nb_dims> &pc ) : pc( pc ) {
}

DTP PolyCon<Scalar,nb_dims> UTP::transform() {
    Vec<Point>  new_f_dirs;
    Vec<Scalar> new_f_offs;
    Vec<Point>  new_b_dirs;
    Vec<Scalar> new_b_offs;

    //
    if constexpr( nb_dims == 0 ) {
        new_f_offs.append( pc.f_offs );
        return { new_f_dirs, new_f_offs, new_b_dirs, new_b_offs };
    } else {
        // equality constraint => actually working at most on `nb_dims - 1` dimensions
        if ( Opt<std::pair<Point,Point>> p = first_eq_bnd() )
            return transform_without_dir( p->first, p->second, false );

        //     used_fs = std::vector<bool>( m_dirs.size(), false );
        //     used_bs = std::vector<bool>( b_dirs.size(), false );

        //
        const auto add_bnd = [&]( Point dir, const Point &in ) {
            if ( norm_2( dir ) == 0 )
                return;
            dir = dir / norm_2( dir );
            auto off = sp( dir, in );

            for( PI i = 0; i < new_b_dirs.size(); ++i ) {
                // TODO: a robust criterium
                if ( norm_2_p2( new_b_dirs[ i ] - dir ) < 1e-12 ) {
                    new_b_offs[ i ] = std::max( new_b_offs[ i ], off );
                    return;
                }
            }

            new_b_dirs << dir;
            new_b_offs << sp( dir, in );
        };

        //
        const auto add_pnt = [&]( Point dir, Scalar off ) {
            for( PI i = 0; i < new_f_dirs.size(); ++i ) {
                // TODO: a robust criterium
                if ( norm_2_p2( new_f_dirs[ i ] - dir ) < 1e-12 ) {
                    new_f_offs[ i ] = std::min( new_f_offs[ i ], off );
                    return;
                }
            }

            new_f_dirs << dir;
            new_f_offs << off;
        };

        //
        used_fs = { FromSizeAndItemValue(), pc.f_dirs.size(), false };
        used_bs = { FromSizeAndItemValue(), pc.b_dirs.size(), false };
        pc.for_each_cell( [&]( Cell<Scalar,nb_dims> &cell ) {
            cell.for_each_vertex( [&]( const Vertex<Scalar,nb_dims> &v ) {
                // add point
                CountOfCutTypes cct;
                cell.add_cut_types( cct, v, pc.nb_bnds() );
                if ( cct.nb_infs == 0 )
                    add_pnt( v.pos, sp( v.pos, *cell.orig_point ) - pc.f_offs[ cell.orig_index ] );

                // update used_fs and used_ms
                for( PI num_cut : v.num_cuts ) {
                    SI ind = cell.cuts[ num_cut ].n_index;
                    if ( ind >= SI( pc.nb_bnds() ) )
                        used_fs[ ind - pc.nb_bnds() ] = true;
                    else if ( ind >= 0 )
                        used_bs[ ind ] = true;
                }
            } );

            cell.for_each_edge( [&]( Vec<PI,nb_dims-1> num_cuts, const Vertex<Scalar,nb_dims> &v0, const Vertex<Scalar,nb_dims> &v1 ) {
                CountOfCutTypes cct0; cell.add_cut_types( cct0, v0, pc.nb_bnds() );
                CountOfCutTypes cct1; cell.add_cut_types( cct1, v1, pc.nb_bnds() );
                if ( cct0.nb_infs == 1 && cct1.nb_infs == 0 )
                    add_bnd( v0.pos - v1.pos, *cell.orig_point );
                if ( cct1.nb_infs == 1 && cct0.nb_infs == 0 )
                    add_bnd( v1.pos - v0.pos, *cell.orig_point );
            } );
        } );

        // if already lies in a sub-space...
        if ( Opt<std::pair<Point,Point>> p = unused_dir() )
            return transform_without_dir( p->first, p->second, true );

        return { new_f_dirs, new_f_offs, new_b_dirs, new_b_offs };
    }
}

DTP Opt<std::pair<typename UTP::Point,typename UTP::Point>> UTP::unused_dir() {
    //

    // starting point
    const PI not_used = -1;
    PI first_used_m = not_used;
    for( PI n = 0; n < used_fs.size(); ++n ) {
        if ( used_fs[ n ] ) {
            first_used_m = n;
            break;
        }
    }

    // covariance matrix
    Point init_dir( FromItemValue(), 0 );
    if ( first_used_m != not_used )
        init_dir = pc.f_dirs[ first_used_m ];

    using CovMat = Eigen::Matrix<Scalar,nb_dims,nb_dims>;
    CovMat cov_mat;
    for( PI r = 0; r < nb_dims; ++r )
        for( PI c = 0; c < nb_dims; ++c )
            cov_mat.coeffRef( r, c ) = 0;
    for( PI n = first_used_m + 1; n < used_fs.size(); ++n ) {
        if ( ! used_fs[ n ] )
            continue;
        Point dir = Point( pc.f_dirs[ n ] ) - init_dir;
        Scalar cdi = norm_2_p2( dir );
        for( PI r = 0; r < nb_dims; ++r )
            for( PI c = 0; c < nb_dims; ++c )
                cov_mat.coeffRef( r, c ) += dir[ r ] * dir[ c ] / cdi;
    }
    for( PI n = 0; n < used_bs.size(); ++n ) {
        if ( ! used_bs[ n ] )
            continue;
        Point dir = pc.b_dirs[ n ];
        Scalar cdi = norm_2_p2( dir );
        for( PI r = 0; r < nb_dims; ++r )
            for( PI c = 0; c < nb_dims; ++c )
                cov_mat.coeffRef( r, c ) += dir[ r ] * dir[ c ] / cdi;
    }

    Eigen::FullPivLU<CovMat> lu( cov_mat );
    if ( lu.dimensionOfKernel() )
        return std::make_pair( init_dir, Point( lu.kernel().col( 0 ) ) );

    return {};
}

DTP PolyCon<Scalar,nb_dims> UTP::transform_without_dir( Point pos, Point dir, bool add_bnd ) {
    // normalization of dir
    dir = dir / norm_2( dir );

    // a simple grahm shmidt to find a base
    Vec<Vec<Scalar,nb_dims>,nb_dims-1> base;
    PI dir_to_avoid = argmax( abs( dir ) );
    for( PI i = 0, j = 0; i < nb_dims; ++i ) {
        if ( i != dir_to_avoid ) {
            Point b{ FromItemValue(), 0 };
            b[ i ] = 1;

            b = b - sp( b, dir ) * dir;
            for( PI k = 0; k < j; ++k )
                b = b - sp( b, base[ k ] ) * base[ k ];
            b = b / norm_2( b );

            base[ j++ ] = b;
        }
    }

    // make new inputs from projection
    using PPoint = Vec<Scalar,nb_dims-1>;
    Vec<PPoint> pm_dirs( FromReservationSize(), pc.f_offs.size() );
    Vec<Scalar> pm_offs( FromReservationSize(), pc.f_offs.size() );
    for( PI i = 0; i < pc.f_offs.size(); ++i ) {
        Point m_dir = pc.f_dirs[ i ];

        PPoint pm_dir;
        for( PI d = 0; d < nb_dims - 1; ++d )
            pm_dir[ d ] = sp( m_dir - pos, base[ d ] );
        pm_dirs << pm_dir;

        pm_offs << pc.f_offs[ i ] - sp( m_dir, pos );
    }

    Vec<PPoint> pb_dirs( FromReservationSize(), pc.b_offs.size() );
    Vec<Scalar> pb_offs( FromReservationSize(), pc.b_offs.size() );
    for( PI i = 0; i < pc.b_offs.size(); ++i ) {
        Point b_dir = pc.b_dirs[ i ];
        if ( all( b_dir == dir ) || all( b_dir == ( -1 ) * dir ) )
            continue;

        PPoint pb_dir;
        for( PI d = 0; d < nb_dims - 1; ++d )
            pb_dir[ d ] = sp( b_dir, base[ d ] );
        pb_dirs << pb_dir;

        pb_offs << pc.b_offs[ i ] - sp( b_dir, pos );
    }

    // make a legendre transform with the new base
    PolyCon<Scalar,nb_dims-1> pnlt( pm_dirs, pm_offs, pb_dirs, pb_offs );
    auto plt = pnlt.legendre_transform();

    Vec<PPoint> &nf_dirs = plt.f_dirs;
    Vec<Scalar> &nf_offs = plt.f_offs;
    Vec<PPoint> &nb_dirs = plt.b_dirs;
    Vec<Scalar> &nb_offs = plt.b_offs;

    // inverse projection
    Vec<Point> im_dirs( FromReservationSize(), nf_offs.size() );
    Vec<Scalar> im_offs( FromReservationSize(), nf_offs.size() );
    for( PI i = 0; i < nf_offs.size(); ++i ) {
        PPoint nm_dir = nf_dirs[ i ];
        Scalar im_off = nf_offs[ i ];
        Point im_dir;
        for( PI e = 0; e < nb_dims; ++e ) {
            Scalar v = pos[ e ];
            for( PI d = 0; d < nb_dims - 1; ++d ) {
                v += nm_dir[ d ] * base[ d ][ e ];
                im_off += nm_dir[ d ] * base[ d ][ e ] * pos[ e ];
            }
            im_dir[ e ] = v;
        }

        im_dirs << im_dir;
        im_offs << im_off;
    }

    Vec<Point> ib_dirs( FromReservationSize(), nb_offs.size() );
    Vec<Scalar> ib_offs( FromReservationSize(), nb_offs.size() );
    for( PI i = 0; i < nb_offs.size(); ++i ) {
        PPoint nb_dir = nb_dirs[ i ];
        Scalar ib_off = nb_offs[ i ];
        Point ib_dir;
        for( PI e = 0; e < nb_dims; ++e ) {
            Scalar v = 0;
            for( PI d = 0; d < nb_dims - 1; ++d ) {
                v += nb_dir[ d ] * base[ d ][ e ];
                ib_off += nb_dir[ d ] * base[ d ][ e ] * pos[ e ];
            }
            ib_dir[ e ] = v;
        }

        ib_dirs << ib_dir;
        ib_offs << ib_off;
    }

    // add equalities for kernel vectors
    if ( add_bnd ) {
        const auto s = sp( dir, pos );

        ib_dirs << dir;
        ib_offs << s;

        ib_dirs << -dir;
        ib_offs << -s;
    }

    return { im_dirs, im_offs, ib_dirs, ib_offs };
}

DTP Opt<std::pair<typename UTP::Point,typename UTP::Point>> UTP::first_eq_bnd() {
    for( PI i = 0; i < pc.b_dirs.size(); ++i ) {
        Point bdi = pc.b_dirs[ i ];
        for( PI j = 0; j < i; ++j ) {
            Point bdj = pc.b_dirs[ j ];
            if ( all( bdi == -bdj ) && pc.b_offs[ i ] == -pc.b_offs[ j ] )
                return std::make_pair( pc.b_offs[ i ] / norm_2_p2( bdi ) * bdi, bdi );
        }
    }
    return {};
}

// DTP PI UTP::nb_inf_cuts( const auto *cuts ) {
//     PI res = 0;
//     for( PI i = 0; i <= nb_dims; ++i )
//         if ( inf_cut( cuts[ i ] ) )
//             ++res;
//     return res;
// }

// DTP void UTP::make_new_affs( Vec<Point> &new_m_dirs, Vec<Scalar> &new_m_offs, const auto &vertex_coords, const auto &vertex_cuts ) {
//     // system to solve for the new cell
//     using EMat = Eigen::Matrix<Scalar,nb_dims+1,nb_dims+1>;
//     using EVec = Eigen::Matrix<Scalar,nb_dims+1,1>;
//     EMat M;
//     EVec V;
//     for( PI num_vertex = 0; num_vertex < vertex_coords.size() / nb_dims; ++num_vertex ) {
//         const auto *coords = vertex_coords.data() + num_vertex * ( nb_dims + 0 );
//         const auto *cuts = vertex_cuts.data() + num_vertex * ( nb_dims + 1 );
//         if ( nb_inf_cuts( cuts ) )
//             continue;

//         for( PI r = 0; r <= nb_dims; ++r ) {
//             PI cut_id = cuts[ r ];

//             // cut coming from an affine function
//             if ( auto ci = aff_cut( cut_id ) ) {
//                 Point dir = m_dirs[ *ci ];
//                 for( PI c = 0; c < nb_dims; ++c )
//                     M( r, c ) = dir[ c ];
//                 M( r, nb_dims ) = -1;
//                 V( r ) = f_offs[ *ci ];
//                 continue;
//             }

//             // cut coming from a boundary
//             if ( auto ci = bnd_cut( cut_id ) ) {
//                 auto bnd = b_dirs[ *ci ];
//                 for( PI c = 0; c < nb_dims; ++c )
//                     M( r, c ) = bnd[ c ];
//                 M( r, nb_dims ) = 0;

//                 Scalar v = 0;
//                 for( PI c = 0; c < nb_dims; ++c )
//                     v += bnd[ c ] * coords[ c ];
//                 V( r ) = v;
//                 continue;
//             }

//             // ?
//             ERROR( "should not happen" );
//         }

//         // solve
//         Eigen::FullPivLU<EMat> lu( M );
//         EVec X = lu.solve( V );

//         // data for the new cell
//         new_m_dirs << Point( FromIterator(), X.data() );
//         new_m_offs << X[ nb_dims ];
//     }
// }

// DTP void UTP::make_new_bnds( Vec<Point> &new_b_dirs, Vec<Scalar> &new_b_offs, const auto &vertex_coords, const auto &vertex_cuts ) {
//     using EMat = Eigen::Matrix<Scalar,nb_dims+1,nb_dims+1>;
//     using EVec = Eigen::Matrix<Scalar,nb_dims+1,1>;
//     using std::sqrt;

//     EMat M;
//     // EVec V;
//     for( PI num_vertex = 0; num_vertex < vertex_coords.size() / nb_dims; ++num_vertex ) {
//         const auto *coords = vertex_coords.data() + num_vertex * ( nb_dims + 0 );
//         const auto *cuts = vertex_cuts.data() + num_vertex * ( nb_dims + 1 );
//         if ( nb_inf_cuts( cuts ) != 1 )
//             continue;

//         for( PI r = 0; r <= nb_dims; ++r ) {
//             // cell cut
//             if ( auto ci = aff_cut( cuts[ r ] ) ) {
//                 Point dir = m_dirs[ *ci ];
//                 for( PI c = 0; c < nb_dims; ++c )
//                     M( r, c ) = dir[ c ];
//                 M( r, nb_dims ) = -1;
//                 // V( r ) = 0;
//                 continue;
//             }

//             // boundary cut
//             if ( auto ci = bnd_cut( cuts[ r ] ) ) {
//                 Point bnd = b_dirs[ *ci ];
//                 for( PI c = 0; c < nb_dims; ++c )
//                     M( r, c ) = bnd[ c ];
//                 M( r, nb_dims ) = 0;
//                 // V( r ) = 0;
//                 continue;
//             }

//             // infnite cut => we say for now that the sum of the coefficients must be == 1
//             //  the direction will be corrected in a second phase
//             if ( auto ci = inf_cut( cuts[ r ] ) ) {
//                 //     for( PI c = 0; c < nb_dims; ++c )
//                 //         M( r, c ) = 1;
//                 //     M( r, nb_dims ) = 0;
//                 //     V( r ) = 1;
//                 for( PI c = 0; c <= nb_dims; ++c )
//                     M( r, c ) = 0;
//                 continue;
//             }

//             // ?
//             ERROR( "should not happen" );
//         }


//         // solve
//         Eigen::FullPivLU<EMat> lu( M );
//         ASSERT( lu.dimensionOfKernel() >= 1 );
//         //std::cout << lu.kernel() << std::endl;
//         // TODO;
//         EVec X = lu.kernel().col( 0 );

//         // coeff for normalization
//         Scalar cnorm = 0;
//         for( PI r = 0; r < nb_dims; ++r )
//             cnorm += X[ r ] * X[ r ];
//         cnorm = 1 / sqrt( cnorm );

//         // check orientation
//         auto bad_new_bnd_orientation = [&]() {
//             using namespace std;
//             Scalar best_sp = 0;

//             // test with boundaries
//             for( PI i = 0; i < b_dirs.size(); ++i ) {
//                 if ( ! used_bs[ i ] )
//                     continue;
//                 Scalar prop_sp = 0;
//                 Point b_dir = b_dirs[ i ];
//                 for( PI d = 0; d < nb_dims; ++d )
//                     prop_sp += b_dir[ d ] * X[ d ];
//                 if ( abs( best_sp ) < abs( prop_sp ) )
//                     best_sp = prop_sp;
//             }

//             // test with other affine functions
//             for( PI i = 0; i < m_dirs.size(); ++i ) {
//                 if ( ! used_fs[ i ] )
//                     continue;
//                 Scalar prop_sp = - X[ nb_dims ];
//                 Point m_dir = m_dirs[ i ];
//                 for( PI d = 0; d < nb_dims; ++d )
//                     prop_sp += m_dir[ d ] * X[ d ];
//                 if ( abs( best_sp ) < abs( prop_sp ) )
//                     best_sp = prop_sp;
//             }

//             return best_sp > 0;
//         };
//         if ( bad_new_bnd_orientation() )
//             cnorm = - cnorm;
//         X *= cnorm;

//         // data for the new cell
//         new_b_dirs << Point( FromIterator(), X.data() );
//         new_b_offs << X[ nb_dims ];
//     }
// }

// DTP Opt<PI> UTP::aff_cut( PI cut ) const {
//     return cut < m_dirs.size() ? cut : Opt<PI>{};
// }

// DTP Opt<PI> UTP::bnd_cut( PI cut ) const {
//     return cut >= m_dirs.size() && cut - m_dirs.size() < b_dirs.size() ? cut - m_dirs.size() : Opt<PI>{};
// }

// DTP Opt<PI> UTP::inf_cut( PI cut ) const {
//     return cut >= m_dirs.size() + b_dirs.size() ? cut - ( m_dirs.size() + b_dirs.size() ) : Opt<PI>{};
// }

#undef DTP
#undef UTP
