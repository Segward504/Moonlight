//
//  main.cpp
//  Moonlight
//

#include <iostream>
#include "Vec3.hpp"
#include "Population.hpp"
#include "DNN.hpp"

int main(int argc, const char * argv[]) {
    
    DNN a = DNN();
    // assigned random weights
    a.Generate();
    
    DNN b = DNN();
    // assigned random weights
    b.Generate();
    
    DNN c = DNN();
    // assigned a split weights inherited from a and b
    c.Inherit(a, b);
    
    return 0;
}

