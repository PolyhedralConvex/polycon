#pragma once

#include <PowerDiagram/PowerDiagram.h>

/**
 * @brief polyhedral convex function
 * 
 */
template<class Scalar,int nb_dims>
class PolyCon { STD_METIL_TYPE_INFO( PolyCon, "...", f_dirs, f_offs, b_dirs, b_offs )
public:
    using       Point             = Vec<Scalar,nb_dims>;

    /**/        PolyCon           ( Span<Point> f_dirs = {}, Span<Scalar> f_offs = {}, Span<Point> b_dirs = {}, Span<Scalar> b_offs = {} );

    PolyCon     legendre_transform();
    void        get_power_diagram ( const std::function<void( PowerDiagram<Scalar,nb_dims> &pd )> &f );
    void        for_each_cell     ( const std::function<void( Cell<Scalar,nb_dims> &cell )> &f );
    void        display_vtk       ( VtkOutput &vo, bool elevation = true );
    PI          nb_bnds           () const;

    Vec<Point>  f_dirs;
    Vec<Scalar> f_offs;
    Vec<Point>  b_dirs;
    Vec<Scalar> b_offs;
};

#include "PolyCon.tcc"
