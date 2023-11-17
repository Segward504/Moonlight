//
//  main.cpp
//  Neural Network 4
//

#include "nn.h"

int main(int argc, const char * argv[]) {
    
    // example making of input and target
    vector<vector<double>> input__ = {{1},{1}};
    vector<vector<double>> target__ = {{1},{1},{1}};
    Array2d input = Array2d(input__);
    Array2d target = Array2d(target__);
    
    // create a new neural network variable
    NeuralNetwork Test = NeuralNetwork(2, 3, 3);
    
    // backpropagates and returns total cost
    const double cost = Test.BackPropagate(input, target);

    
    return 0;
}
