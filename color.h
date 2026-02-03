
#pragma once

#include "vec3.h"

using color = point3;

void write_color(std::ostream& out, const color& pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // translate [0, 1] -> byte range [0, 255]
    int rbyte = int(r * 255.999);
    int gbyte = int(g * 255.999);
    int bbyte = int(b * 255.999);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

