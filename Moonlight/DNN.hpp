//
//  DNN.hpp
//  Moonlight
//

#ifndef DNN_hpp
#define DNN_hpp

#include <stdio.h>
#include <iostream>
#include <random>

#endif /* DNN_hpp */

#define e 2.71828182845904523536

using namespace std;

class DNN {
public:
    // Variables
    int inputnodes = 4;
    int hiddenlayers = 2;
    int hiddennodes = 5;
    int outputnodes = 3;
    
    std::vector<double> inputarray;
    std::vector<std::vector<double>> hiddenarray;
    std::vector<double> outputarray;
    
    std::vector<std::vector<double>> inputhiddenweights;
    std::vector<std::vector<std::vector<double>>> hiddenhiddenweights;
    std::vector<std::vector<double>> hiddenoutputweights;
    
    // Constructor
    DNN();
    // Functions
    void ForwardFeed();
    void SetInputArray(std::vector<double> a);
    void Generate(); // randomized weights
    void Inherit(DNN a, DNN b); // inherited or reproduced weights
    void Mutate();
    double Rand();
    double Sigmoid(double a);
    
private:
};
