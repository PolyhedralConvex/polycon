#pragma once

#include <PowerDiagram/support/Opt.h>
#include <PowerDiagram/Point.h>

#define LegendreTransform CC_DT( LegendreTransform )

///
struct LegendreTransform {
    using                Ret                  = std::tuple<Vec<Point>,Vec<Scalar>,Vec<Point>,Vec<Scalar>>;

    /**/                 LegendreTransform    ( Span<Point> f_dirs, Span<Scalar> f_offs, Span<Point> b_dirs, Span<Scalar> b_offs );

    Ret                  transform_without_dir( Point pos, Point dir, bool add_bnd );
    Ret                  transform            ();

    // void              update_used_ms_and_bs( const auto &vertex_coords, const auto &vertex_cuts );
    // void              make_new_affs        ( Vec<Point> &nm_dirs, Vec<Scalar> &nm_offs, const auto &vertex_coords, const auto &vertex_cuts );
    // void              make_new_bnds        ( Vec<Point> &nb_dirs, Vec<Scalar> &nb_offs, const auto &vertex_coords, const auto &vertex_cuts );
    auto                 first_eq_bnd         () -> Opt<std::pair<Point,Point>>;
    // PI                nb_inf_cuts          ( const auto *cuts );
    // auto              unused_dir           () -> Opt<std::pair<Point,Point>>;
    // Opt<PI>           aff_cut              ( PI cut ) const;
    // Opt<PI>           bnd_cut              ( PI cut ) const;
    // Opt<PI>           inf_cut              ( PI cut ) const;

    // Ci_nb_dims        ci_nb_dims;
    // Ct_Scalar         ct_Scalar;
    Span<Point>          f_dirs;
    Span<Scalar>         f_offs;
    Span<Point>          b_dirs;
    Span<Scalar>         b_offs;

    // std::vector<bool> used_ms;
    // std::vector<bool> used_bs;
};

