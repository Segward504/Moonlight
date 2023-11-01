//
//  DNN.hpp
//  Moonlight
//

#ifndef DNN_hpp
#define DNN_hpp

#include <stdio.h>
#include <iostream>

#endif /* DNN_hpp */

using namespace std;

class DNN {
public:
    // Variables
    int inputnodes;
    int hiddenlayers;
    int hiddennodes;
    int outputnodes;
    
    std::vector<double> inputarray;
    std::vector<std::vector<double>> hiddenarray;
    std::vector<double> outputarray;
    
    std::vector<std::vector<double>> inputhiddenweights;
    std::vector<std::vector<std::vector<double>>> hiddenhiddenweights;
    std::vector<std::vector<double>> outputhiddenweights;
    
    // Constructor
    DNN();
    // Functions
    void ForewardFeed();
    void SetInputArray();
    void Generate(); // randomized weights
    void Inherit(DNN a, DNN b); // inherited or reproduced weights
private:
    
};
