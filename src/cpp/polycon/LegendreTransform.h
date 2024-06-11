#pragma once

#include <PowerDiagram/support/Opt.h>
#include "PolyCon.h"

/**
 * @brief Helper to compute a legendre transformation from a PolyCon
 */
template<class Scalar,int nb_dims>
struct LegendreTransform {
    using                    Point                = Vec<Scalar,nb_dims>;

    /**/                     LegendreTransform    ( const PolyCon<Scalar,nb_dims> &pc );

    PolyCon<Scalar,nb_dims>  transform_without_dir( Point pos, Point dir, bool add_bnd );
    PolyCon<Scalar,nb_dims>  transform            ();

    // void                  update_used_ms_and_bs( const auto &vertex_coords, const auto &vertex_cuts );
    // void                  make_new_affs        ( Vec<Point> &nm_dirs, Vec<Scalar> &nm_offs, const auto &vertex_coords, const auto &vertex_cuts );
    // void                  make_new_bnds        ( Vec<Point> &nb_dirs, Vec<Scalar> &nb_offs, const auto &vertex_coords, const auto &vertex_cuts );
    auto                     first_eq_bnd         () -> Opt<std::pair<Point,Point>>;
    // PI                    nb_inf_cuts          ( const auto *cuts );
    auto                     unused_dir           () -> Opt<std::pair<Point,Point>>;
    // Opt<PI>               aff_cut              ( PI cut ) const;
    // Opt<PI>               bnd_cut              ( PI cut ) const;
    // Opt<PI>               inf_cut              ( PI cut ) const;

    // Ci_nb_dims            ci_nb_dims;
    // Ct_Scalar             ct_Scalar;
    Vec<bool>                used_fs;
    Vec<bool>                used_bs;
    PolyCon<Scalar,nb_dims>  pc;

};

#include "LegendreTransform.tcc"
