//
//  Element.hpp
//  Moonlight
//

#ifndef Element_hpp
#define Element_hpp

#include <stdio.h>
#include <iostream>
#include "DNN.hpp"
#include "Vec3.hpp"

#endif /* Element_hpp */

using namespace std;

class Element {
public:
    
    DNN dnn = DNN();
    Vec3 pos = Vec3(0, 0, 0);
    double rotation = 0;
    double fitness = 0;
    
    // Constructor
    Element();
    
    // Functions
    void Generate();
    void SetInput(Element b);
    void CalculateFitness(Element b);
    void Update();
    void Forward();
    void RotateLeft();
    void RotateRight();
    
private:
    
};
