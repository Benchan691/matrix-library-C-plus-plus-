#include <cmath>
#include <iostream>
#include <vector>
#include "math_tools.h"

using namespace std;



Matrix::Matrix(uint32_t rows, uint32_t cols)
    : _cols(cols), _rows(rows), _vals({})
{
    _vals.resize(rows, vector<float>(cols));

};

float Matrix::at(uint32_t row, uint32_t col) {
    return _vals[row][col];
}

Matrix Matrix::multiply(Matrix& target) {

    Matrix output(_rows, target._cols);

    for (int y = 0; y < output._vals.size(); y++) {

        for (int x = 0; x < output._vals[y].size(); x++) {
            int sum = 0;
            for (int z = 0; z < target._rows; z++) {
                sum += _vals[y][z] * target._vals[z][x];
            }
            output._vals[y][x] = sum;
        }
    }

    return output;

}

Matrix Matrix::add(Matrix& target) {
    Matrix output(target._rows, _cols);

    for (int y = 0; y < _rows; y++) {
        for (int x = 0; x < _cols; x++) {
            output._vals[y][x] = target._vals[y][x] + _vals[y][x];

        }
    }

    return output;

}

Matrix Matrix::substract(Matrix& target) {
    Matrix output(target._rows, _cols);

    for (int y = 0; y < _rows; y++) {
        for (int x = 0; x < _cols; x++) {
            output._vals[y][x] = _vals[y][x] - target._vals[y][x];
        }
    }

    return output;
}

void Matrix::print_matrix() {
    for (int y = 0; y < _rows; y++) {
        for (int x = 0; x < _cols; x++) {
            cout << _vals[y][x] << ' ';
        }
        cout << endl;
    }
}

void Matrix::read_matrix() {
    for (int y = 0; y < _rows; y++) {
        for (int x = 0; x < _cols; x++) {
            cin >> _vals[y][x];
        }
    }
}

Matrix Matrix::tranpose() {
    Matrix output(_cols, _rows);
    for (int y = 0; y < _cols; y++) {
        for (int x = 0; x < _rows; x++) {
            output._vals[y][x] = _vals[x][y];
        }
    }
    return output;
}

void Layer::forward_prop(Layer& before) {
    for (int x = 0; x < before.weight.size(); x++) {
        auto e = before.node.tranpose().multiply(before.weight[x]);
        node.add(e);
    }
}

Layer::Layer(uint32_t _size, Layer& before) : size(_size) {
    node._vals.resize(1, vector<float>(size));
    weight.resize(before.size, Matrix(1, size));
}
