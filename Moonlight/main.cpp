//
//  main.cpp
//  Moonlight
//

#include <iostream>
#include "Vec3.hpp"
#include "Population.hpp"

int main(int argc, const char * argv[]) {
    
    int Generations = 100;
    int PopulationSize = 100;
    
    Population Pop = Population(PopulationSize);
    
    // test of dot:
    // Vec3 Position = Vec3(5, 0, 5);
    // Vec3 LookVector = Vec3(-1,0,-1);
    // Vec3 Target = Vec3(0, 0, 0);
    // Vec3 Delta = Target.Subtract(Position).Unit();
    // double Dot = Delta.Dot(LookVector);
    // std::cout << Dot << "\n";

    return 0;
}

