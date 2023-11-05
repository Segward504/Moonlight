//
//  main.cpp
//  Moonlight
//

// inputs
// delta position, dot rotation

// outputs
// forward, rotateleft, rotateright

#include <iostream>
#include "Element.hpp"

int main(int argc, const char * argv[]) {
    
    Element a = Element();
    Element b = Element();
    
    a.pos = Vec3(1, 0, 1);
    b.pos = Vec3(10, 0, 10);
    
    a.Generate();
    b.Generate();
    
    for (int i = 0; i < 10; i++) {
        a.SetInput(b);
        a.Update();
        a.CalculateFitness(b);
    }
    
    return 0;
}



