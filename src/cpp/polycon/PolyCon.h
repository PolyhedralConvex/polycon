#pragma once

#include <PowerDiagram/PowerDiagram.h>

#define PolyCon CC_DT( PolyCon )

/**
 * @brief 
 * 
 */
class PolyCon { STD_METIL_TYPE_INFO( PolyCon, f_dirs, f_offs, b_dirs, b_offs )
public:
    /**/        PolyCon           ( Span<Point> f_dirs, Span<Scalar> f_offs, Span<Point> b_dirs, Span<Scalar> b_offs );

    PolyCon     legendre_transform();
    void        get_power_diagram ( const std::function<void( PowerDiagram &pd )> &f );
    void        for_each_cell     ( const std::function<void( Cell &cell )> &f );
    void        display_vtk       ( VtkOutput &vo, bool elevation = true );
    static Str  type_name         ();

    Vec<Point>  f_dirs;
    Vec<Scalar> f_offs;
    Vec<Point>  b_dirs;
    Vec<Scalar> b_offs;
};
