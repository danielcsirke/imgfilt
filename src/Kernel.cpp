#include "types/Kernel.hpp"
#include <stdexcept>
#include <utility> // for std::move
#include <cmath> // for std::abs


Kernel::Kernel(KernelMatrix values) : kernelValues(std::move(values)) { // im passing the argument by value, because after that I move it, this is why it isn't passed by reference
    if (rows() % 2 == 0 || cols() % 2 == 0) { // check whether the passed kernel has odd size rows and cols (row and col numbers can be different don't have to be nxn matrice)
        throw std::invalid_argument("Kernel must have odd dimensions.");
    }
}

int Kernel::cols() const {
    return kernelValues.empty() ? 0 : kernelValues[0].size(); // check whether it has any elements, if it has, then calculate the size of the first row
}

int Kernel::rows() const {
    return kernelValues.size();
}

int Kernel::centerX() const {
    return (cols()-1) / 2;
}

int Kernel::centerY() const {
    return (rows()-1) / 2;
}

int Kernel::absToRel(int coordinate, int size) const {
    return coordinate - ((size - 1) / 2); // works only for odd sized kernels; math: relative coordinate = abs coordinate - center 
}

double Kernel::getValue(int row, int col) const {
    if (row < 0 || row >= rows() || col < 0 || col >= cols()) {
        throw std::out_of_range("Kernel index out of range.");
    }
    return kernelValues[row][col];
}

void Kernel::set(int row, int col, double value) {
    if (row < 0 || row >= rows() || col < 0 || col >= cols()) {
        throw std::out_of_range("Kernel index out of range.");
    }
    kernelValues[row][col] = value;
}

void Kernel::set(const KernelMatrix& values) {
    kernelValues = values;
}

const KernelMatrix& Kernel::getValues() const {
    return kernelValues;
}

KernelMatrix& Kernel::getValues() {
    return kernelValues;
}

double Kernel::sum() const {
    double sum = 0.0;
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < cols(); ++j) {
            sum += kernelValues[i][j];
        }
    }
    return sum;
}

void Kernel::normalize(double epsilon) {
    double sum = this->sum();
    if (std::abs(sum) < epsilon) {
        throw std::runtime_error("Kernel sum is too close to zero, cannot normalize.");
    }
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < cols(); ++j) {
            kernelValues[i][j] /= sum;
        }
    }
}


bool Kernel::isNormalized(double epsilon) const {
    double sum = this->sum();
    return std::abs(sum - 1.0) < epsilon; // check if the sum is close to 1.0
}

void Kernel::scale(double factor) {
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < cols(); ++j) {
            kernelValues[i][j] *= factor;
        }
    }
}


