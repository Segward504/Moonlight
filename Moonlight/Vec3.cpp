//
//  Vec3.cpp
//  Moonlight
//

#include "Vec3.hpp"

Vec3::Vec3(double ax, double ay, double az) {
    x = ax;
    y = ay;
    z = az;
}

double Vec3::Dot(Vec3 b) {
    return x * b.x + y * b.y + z * b.z;
    
}

double Vec3::Normal() {
    // getting the magnitude but squared
    double Normal = pow(x + y + z, 2);
    // returning the root of the square
    return sqrt(Normal);
}

Vec3 Vec3::Unit() {
    // getting the normal
    double n = Normal();
    // getting multiplier needed to downscale
    double m = 1/n;
    // bring Vec3 down in scale
    Vec3 u = Vec3(x * m, y * m, z * m);
    return u;
}

Vec3 Vec3::Subtract(Vec3 b) {
    return Vec3(x - b.x, y - b.y, z - b.z);
}

Vec3 Vec3::Addition(Vec3 b) {
    return Vec3(x + b.x, y + b.y, z + b.z);
}

