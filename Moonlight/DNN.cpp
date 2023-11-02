//
//  DNN.cpp
//  Moonlight
//

#include "DNN.hpp"
#include <random>

DNN::DNN() {
    // Make the inputarray with content
    for (int i = 0; i < inputnodes; i++) {
        inputarray.push_back(0);
    }
    // Make the hiddenlayers with content
    for (int i = 0; i < hiddenlayers; i++) {
        std::vector<double> nodes;
        for (int j = 0; j < hiddennodes; j++) {
            nodes.push_back(0);
        }
        hiddenarray.push_back(nodes);
    }
    // Make the outputarray with content
    for (int i = 0; i < outputnodes; i++) {
        outputarray.push_back(0);
    }
}

void DNN::SetInputArray(std::vector<double> a) {
    for (int i = 0; i < inputnodes; i++) {
        inputarray[i] = a[i];
    }
}

void DNN::ForewardFeed() {
    for (int i = 0; i < hiddennodes; i++) {
        double sum = 0;
        for (int j = 0; j < inputnodes; j++) {
            sum += inputhiddenweights[i][j] * inputarray[j];
        }
        hiddenarray[0][i] = sum;
    }
    for (int l = 0; l < hiddenlayers-1; l++) {
        for (int i = 0; i < hiddennodes; i++) {
            double sum = 0;
            for (int j = 0; j < hiddennodes; j++) {
                sum += hiddenhiddenweights[l][i][j] * hiddenarray[l][j];
            }
            hiddenarray[l+1][i] = sum;
        }
    }
    for (int i = 0; i < outputnodes; i++) {
        double sum = 0;
        for (int j = 0; j < hiddennodes; j++) {
            sum += hiddenoutputweights[i][j] * hiddenarray[hiddenlayers-1][j];
        }
        outputarray[i] = sum;
    }
}

void DNN::Generate() {
    for (int i = 0; i < hiddennodes; i++) {
        std::vector<double> weights;
        for (int j = 0; j < inputnodes; j++) {
            weights.push_back(Rand());
        }
        inputhiddenweights.push_back(weights);
    }
    for (int l = 0; l < hiddenlayers-1; l++) {
        std::vector<std::vector<double>> layer;
        for (int i = 0; i < hiddennodes; i++) {
            std::vector<double> weights;
            for (int j = 0; j < inputnodes; j++) {
                weights.push_back(Rand());
            }
            layer.push_back(weights);
        }
        hiddenhiddenweights.push_back(layer);
    }
    for (int i = 0; i < outputnodes; i++) {
        std::vector<double> weights;
        for (int j = 0; j < hiddennodes; j++) {
            weights.push_back(Rand());
        }
        hiddenoutputweights.push_back(weights);
    }
}

void DNN::Inherit(DNN a, DNN b) {
    for (int i = 0; i < hiddennodes; i++) {
        std::vector<double> weights;
        for (int j = 0; j < inputnodes; j++) {
            if (Rand() < 0) {
                weights.push_back(a.inputhiddenweights[i][j]);
            } else {
                weights.push_back(b.inputhiddenweights[i][j]);
            }
        }
        inputhiddenweights.push_back(weights);
    }
    for (int l = 0; l < hiddenlayers-1; l++) {
        std::vector<std::vector<double>> layer;
        for (int i = 0; i < hiddennodes; i++) {
            std::vector<double> weights;
            for (int j = 0; j < inputnodes; j++) {
                if (Rand() < 0) {
                    weights.push_back(a.hiddenhiddenweights[l][i][j]);
                } else {
                    weights.push_back(b.hiddenhiddenweights[l][i][j]);
                }
            }
            layer.push_back(weights);
        }
        hiddenhiddenweights.push_back(layer);
    }
    for (int i = 0; i < outputnodes; i++) {
        std::vector<double> weights;
        for (int j = 0; j < hiddennodes; j++) {
            if (Rand() < 0) {
                weights.push_back(a.hiddenoutputweights[i][j]);
            } else {
                weights.push_back(b.hiddenoutputweights[i][j]);
            }
        }
        hiddenoutputweights.push_back(weights);
    }
}

double DNN::Rand() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-200000, 200000); // define the range
    return (double) distr(gen) * 0.00001; // return double
}
