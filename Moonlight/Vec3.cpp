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

Vec3 Vec3::Unit() {
    
    double length = sqrt(pow(a[0],2) + pow(a[2],2));
    
    // bring Vec3 down in scale
    Vec3 u = Vec3(a[0]/length, a[1]/length, a[2]/length);
    return u;
    
}

Vec3 Vec3::Sub(Vec3 b) {
    return Vec3(a[0] - b.a[0], a[1] - b.a[1], a[2] - b.a[2]);
}

Vec3 Vec3::Add(Vec3 b) {
    return Vec3(a[0] + b.a[0], a[1] + b.a[1], a[2] + b.a[2]);
}

void Vec3::Print() {
    for (double n : a) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}
