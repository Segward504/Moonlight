//
//  array2d.h
//  Neural Network 4
//

#ifndef array2d_h
#define array2d_h


#endif /* array2d_h */

#include <iostream>
#include <random>

using namespace std;

class Array2d {
public:
    
    int rows;
    int columns;
    double ** array;
    
    Array2d() {
        
    }
    
    Array2d(int rows_, int columns_, double ** &array_) {
        
        rows = rows_;
        columns = columns_;
        array = array_;
        
    }
    
    Array2d(vector<vector<double>> &array__) {
        
        rows = (int) array__.size();
        columns = (int) array__[0].size();
        
        double ** array_ = new double * [rows];
        
        for (int i = 0; i < rows; ++i) {
            
            array_[i] = new double [columns];
            
            for (int j = 0; j < columns; ++j) {
                
                array_[i][j] = array__[i][j];
                
            }
        }
        
        array = array_;
        
    }
    
    void Print() {
        
        std::cout << "{";
        
        for (int i = 0; i < rows; i++) {
            
            std::cout << "{";
            
            for (int j = 0; j < columns; j++) {
                
                if (j < columns-1) {
                    
                    std::cout << array[i][j] << ",";
                    
                } else {
                    
                    std::cout << array[i][j];
                    
                }
            }
            if (i < rows-1) {
                
                std::cout << "},";
                
            } else {
                
                std::cout << "}";
                
            }
        }
        
        std::cout << "}" << std::endl;
        
    }
    
    Array2d Multiply(Array2d &b) {

        double ** multiplied = new double * [rows];
        
        for (int i = 0; i < rows; ++i) {
            
            multiplied[i] = new double [b.columns];
            
            for (int j = 0; j < b.columns; ++j) {
                
                double sum = 0;
                
                for (int k = 0; k < b.rows; ++k) {
                    
                    sum += array[i][k] * b.array[k][j];
                    
                }
                
                multiplied[i][j] = sum;
            }
        }
        
        return Array2d(rows, b.columns, multiplied);
        
    }
    
    void Elu() {
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (array[i][j] <= 0) {
                    
                    array[i][j] = exp(array[i][j]) - 1;
                    
                } 
            }
        }
        
    }
    
    Array2d Elu_Derivate() {
        
        double ** activated = new double * [rows];
        
        for (int i = 0; i < rows; i++) {
            
            activated[i] = new double [columns];
            
            for (int j = 0; j < columns; j++) {
                
                if (array[i][j] <= 0) {
                    
                    activated[i][j] = exp(array[i][j]);
                    
                } else {
                    
                    activated[i][j] = 1;
                    
                }
            }
        }
        
        return Array2d(rows, columns, activated);
        
    }
        
    void Add(Array2d &b) {
        
        for (int i = 0; i < rows; i++) {
            
            for (int j = 0; j < columns; j++) {
                
                array[i][j] += b.array[i][j];
                
            }
        }
        
    }
    
    Array2d Subtract(Array2d &b) {
        
        double ** subtracted = new double * [rows];
        
        for (int i = 0; i < rows; i++) {
            
            subtracted[i] = new double [columns];
            
            for (int j = 0; j < columns; j++) {
                
                subtracted[i][j] = array[i][j] - b.array[i][j];
            }
        }
        
        return Array2d(rows, columns, subtracted);
        
    }
    
    Array2d Transpose() {
        
        double ** transposed = new double * [columns];
        
        for (int i = 0; i < columns; i++) {
            
            transposed[i] = new double [rows];
            
            for (int j = 0; j < rows; j++) {
                
                transposed[i][j] = array[j][i];
            }
        }
        
        return Array2d(columns, rows, transposed);
        
    }
    
    void Normalize() {
        
        double biggest = 0;
        
        for (int i = 0; i < rows; i++) {
            
            for (int j = 0; j < columns; j++) {
                
                if (abs(array[i][j]) > biggest) {
                    
                    biggest = abs(array[i][j]);
                    
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            
            for (int j = 0; j < columns; j++) {
                
                array[i][j] = array[i][j]/biggest;
                
            }
        }
        
    }
    
    void Multiply(const double &b) {
        
        for (int i = 0; i < rows; i++) {
            
            for (int j = 0; j < columns; j++) {
                
                array[i][j] *= b;
                
            }
        }
        
    }
    
    void Hadmard_Product(Array2d &b) {
        
        for (int i = 0; i < rows; ++i) {
            
            for (int j = 0; j < columns; ++j) {
                
                array[i][j] *= b.array[i][j];
                
            }
        }
        
    }
    
    double Sum() {
        
        double sum = 0;
        
        for (int i = 0; i < rows; ++i) {
            
            for (int j = 0; j < columns; ++j) {
                
                sum += array[i][j];
                
            }
        }
        
        return sum;
        
    }
    
};
