//
//  nn.h
//  Neural Network 4
//



#ifndef nn_h
#define nn_h


#endif /* nn_h */

#include "array2d.h"

class NeuralNetwork {
    
public:
    
    Array2d weights_input_hidden_1;
    Array2d weights_hidden_hidden_2;
    Array2d weights_hidden_hidden_3;
    Array2d weights_hidden_output;
    Array2d bias_input_hidden_1;
    Array2d bias_hidden_hidden_2;
    Array2d bias_hidden_hidden_3;
    Array2d bias_hidden_output;
    
    const double learning_rate = 0.001;
    
    int input_size;
    int hidden_size;
    int output_size;
    
    NeuralNetwork(int input, int hidden, int output) {
        
        input_size = input;
        hidden_size = hidden;
        output_size = output;
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(-pow(10,4), pow(10,4));
        
        double ** weights_input_hidden_1_ = new double * [hidden];
        double ** weights_hidden_hidden_2_ = new double * [hidden];
        double ** weights_hidden_hidden_3_ = new double * [hidden];
        double ** weights_hidden_output_ = new double * [output];
        double ** bias_input_hidden_1_ = new double * [hidden];
        double ** bias_hidden_hidden_2_ = new double * [hidden];
        double ** bias_hidden_hidden_3_ = new double * [hidden];
        double ** bias_hidden_output_ = new double * [output];
        
        for (int i = 0; i < hidden; ++i) {
            
            weights_input_hidden_1_[i] = new double[input];
            weights_hidden_hidden_2_[i] = new double[hidden];
            weights_hidden_hidden_3_[i] = new double[hidden];
            bias_input_hidden_1_[i] = new double[1];
            bias_hidden_hidden_2_[i] = new double[1];
            bias_hidden_hidden_3_[i] = new double[1];
            
            for (int j = 0; j < input; ++j) {
                weights_input_hidden_1_[i][j] = distr(gen)/pow(10,4);
            }
            
            for (int j = 0; j < hidden; ++j) {
                weights_hidden_hidden_2_[i][j] = distr(gen)/pow(10,4);
                weights_hidden_hidden_3_[i][j] = distr(gen)/pow(10,4);
            }
            
            bias_input_hidden_1_[i][0] = distr(gen)/pow(10,4);
            bias_hidden_hidden_2_[i][0] = distr(gen)/pow(10,4);
            bias_hidden_hidden_3_[i][0] = distr(gen)/pow(10,4);

        }
        
        for (int i = 0; i < output; ++i) {
            weights_hidden_output_[i] = new double [hidden];
            bias_hidden_output_[i] = new double [1];
            
            for (int j = 0; j < hidden; ++j) {
                weights_hidden_output_[i][j] = distr(gen)/pow(10,4);
            }
            
            bias_hidden_output_[i][0] = distr(gen)/pow(10,4);
            
        }
        
        weights_input_hidden_1 = Array2d(hidden, input, weights_input_hidden_1_);
        weights_hidden_hidden_2 = Array2d(hidden, hidden, weights_hidden_hidden_2_);
        weights_hidden_hidden_3 = Array2d(hidden, hidden, weights_hidden_hidden_3_);
        weights_hidden_output = Array2d(output, hidden, weights_hidden_output_);
        bias_input_hidden_1 = Array2d(hidden, 1, bias_input_hidden_1_);
        bias_hidden_hidden_2 = Array2d(hidden, 1, bias_hidden_hidden_2_);
        bias_hidden_hidden_3 = Array2d(hidden, 1, bias_hidden_hidden_3_);
        bias_hidden_output = Array2d(output, 1, bias_hidden_output_);
        
    }
    
    const double BackPropagate(Array2d &input, Array2d &target) {
        
        
        // Forward Pass
        
        Array2d hidden_1 = weights_input_hidden_1.Multiply(input);
        hidden_1.Add(bias_input_hidden_1);
        hidden_1.Elu();
        
        Array2d hidden_2 = weights_hidden_hidden_2.Multiply(hidden_1);
        hidden_2.Add(bias_hidden_hidden_2);
        hidden_2.Elu();
        
        Array2d output = weights_hidden_output.Multiply(hidden_2);
        output.Add(bias_hidden_output);
        output.Elu();
        
        // BackPropagate
        
        // getting cost
        Array2d cost_output = target.Subtract(output);
        
        // getting gradient
        Array2d gradient_output = output.Elu_Derivate();
        gradient_output.Hadmard_Product(cost_output);
        gradient_output.Multiply(learning_rate);
        
        // getting delta
        Array2d hidden_2_transposed = hidden_2.Transpose();
        Array2d delta_weights_output = gradient_output.Multiply(hidden_2_transposed);
        
        // getting cost
        Array2d cost_hidden_2 = weights_hidden_output.Transpose();
        cost_hidden_2.Multiply(cost_output);
        
        // getting gradient
        Array2d gradient_hidden_2 = hidden_2.Elu_Derivate();
        gradient_hidden_2.Hadmard_Product(cost_hidden_2);
        gradient_hidden_2.Multiply(learning_rate);
        
        // getting delta
        Array2d hidden_1_transposed = hidden_1.Transpose();
        Array2d delta_weights_hidden_2 = gradient_hidden_2.Multiply(hidden_1_transposed);
        
        // getting cost
        Array2d cost_hidden_1 = weights_hidden_hidden_2.Transpose();
        cost_hidden_1.Multiply(cost_hidden_2);
        
        // getting gradient
        Array2d gradient_hidden_1 = hidden_1.Elu_Derivate();
        gradient_hidden_1.Hadmard_Product(cost_hidden_1);
        gradient_hidden_1.Multiply(learning_rate);
        
        // getting delta
        Array2d input_transposed = input.Transpose();
        Array2d delta_weights_hidden_1 = gradient_hidden_1.Multiply(input_transposed);
        
        // Update weights
        weights_hidden_output.Add(delta_weights_output);
        weights_hidden_hidden_2.Add(delta_weights_hidden_2);
        weights_input_hidden_1.Add(delta_weights_hidden_1);
        bias_hidden_output.Add(gradient_output);
        bias_hidden_hidden_2.Add(gradient_hidden_2);
        bias_input_hidden_1.Add(gradient_hidden_1);
        
        // return sum of cost output
        return cost_output.Sum();
    }
    
    
};
