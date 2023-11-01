//
//  Vec3.cpp
//  Moonlight
//

#include "Vec3.hpp"

Vec3::Vec3(double x, double y, double z) {
    a = {x, y, z};
}

double Vec3::Dot(Vec3 b) {
    return a[0] * b.a[0] + a[1] * b.a[1] + a[2] * b.a[2];
}

double Vec3::Normal() {
    // getting the normal but squared
    double Normal = pow(a[0] + a[1] + a[2], 2);
    // returning the root of the square
    return sqrt(Normal);
}

Vec3 Vec3::Unit() {
    // getting the normal
    double n = Normal();
    // getting multiplier needed to downscale
    double m = 1/n;
    // bring Vec3 down in scale
    Vec3 u = Vec3(a[0] * m, a[1] * m, a[2] * m);
    return u;
}

Vec3 Vec3::Sub(Vec3 b) {
    return Vec3(a[0] - b.a[0], a[1] - b.a[1], a[2] - b.a[2]);
}

Vec3 Vec3::Add(Vec3 b) {
    return Vec3(a[0] + b.a[0], a[1] + b.a[1], a[2] + b.a[2]);
}

