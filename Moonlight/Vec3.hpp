//
//  Vec3.hpp
//  Moonlight
//


#ifndef Vec3_hpp
#define Vec3_hpp

#include <stdio.h>
#include <iostream>

#endif /* Vec3_hpp */

#define pi 3.141592653589793238462643383279502884197

using namespace std;

class Vec3 {
public:
    // Variables
    std::vector<double> a;
    // Constructor
    Vec3(double x, double y, double z);
    // Functions
    double Dot(Vec3 b);
    Vec3 Unit();
    Vec3 Sub(Vec3 b);
    Vec3 Add(Vec3 b);
    double Normal();
    void Print();
private:
    
};
