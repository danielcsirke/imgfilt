#include "types/Kernel.hpp"
#include <stdexcept>


Kernel::Kernel(KernelMatrix values) : kernelValues(std::move(values)) {
    if (rows() % 2 == 0 || cols() % 2 == 0) {
        throw std::invalid_argument("Kernel must have odd dimensions.");
    }
}

int Kernel::cols() const {
    return kernelValues.empty() ? 0 : kernelValues[0].size();
}