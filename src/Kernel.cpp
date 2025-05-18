#include "types/Kernel.hpp"
#include <stdexcept>


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