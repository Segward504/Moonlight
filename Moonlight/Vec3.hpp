//
//  Vec3.hpp
//  Moonlight
//


#ifndef Vec3_hpp
#define Vec3_hpp

#include <stdio.h>
#include <iostream>

#endif /* Vec3_hpp */

using namespace std;

class Vec3 {
public:
    // Variables
    double x;
    double y;
    double z;
    // Constructor
    Vec3(double ax, double ay, double az);
    // Functions
    double Dot(Vec3 b);
    double Normal();
    Vec3 Unit();
    Vec3 Subtract(Vec3 b);
    Vec3 Addition(Vec3 b);
private:
    
};
