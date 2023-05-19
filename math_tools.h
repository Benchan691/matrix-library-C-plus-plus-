
#include <vector>
#pragma once

using namespace std;
class Matrix {
public:
    uint32_t _cols;
    uint32_t _rows;
    vector<vector<float>> _vals;

public:
    Matrix(uint32_t cols, uint32_t rows);

    float at(uint32_t col, uint32_t row);

    Matrix multiply(Matrix& target);

    Matrix add(Matrix& target);

    Matrix substract(Matrix& target);

    Matrix tranpose();

    void print_matrix();

    void read_matrix();
};

class Layer {
public:
    uint32_t size;
    static Matrix node;
    vector<Matrix> weight;

public:

    Layer(uint32_t _size, Layer& before);



    void forward_prop(Layer& before);
     
};

class Neuron {
public:
    vector<float> receive;
    float val;
public:
    class activation_function {
    public:

        float RELU();
        float softmax();
        float sigmod();

    };


};