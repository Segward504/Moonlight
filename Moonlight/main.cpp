//
//  main.cpp
//  Moonlight
//

// inputs
// delta position, dot rotation

// outputs
// forwar, rotateleft, rotateright

#include <iostream>
#include "Element.hpp"

int main(int argc, const char * argv[]) {
    
    Element a = Element();
    Element b = Element();
    
    a.pos = Vec3(1, 0, 1);
    b.pos = Vec3(10, 0, 10);
    
    a.Generate();
    b.Generate();

    a.SetInput(b);
    a.RotateLeft();
    
    a.SetInput(b);
    
    return 0;
}


