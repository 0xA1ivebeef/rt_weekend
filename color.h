
#pragma once

#include "interval.h"
#include "vec3.h"

using color = vec3;

inline double linear_to_gamma(double l)
{
    if (l > 0)
        return std::sqrt(l);
    return 0;
}

void write_color(std::ostream& out, const color& pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // translate [0, 1] -> byte range [0, 255]
    static const interval intensity(0.000, 0.999);
    int rbyte = int(intensity.clamp(r) * 256);
    int gbyte = int(intensity.clamp(g) * 256);
    int bbyte = int(intensity.clamp(b) * 256);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

