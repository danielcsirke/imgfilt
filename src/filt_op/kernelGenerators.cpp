#include "types/Kernel.hpp"
#include <cmath>
#include <stdexcept>
#include <vector>

namespace kernelGenerators{

Kernel createBoxBlurKernel(int size) {
    // It was made normalized, no need to normalize it again.
    if (size <= 0 || size % 2 == 0) {
        throw std::invalid_argument("Box blur kernel size must be positive and odd.");
    }

    double value = 1.0 / (size * size);
    KernelMatrix matrix(size, std::vector<double>(size, value));

    Kernel kernel(matrix); 
    return kernel;
}


Kernel createGaussianBlurKernel(int size, double sigma) {
    // based on the Gaussian function: 
    // G(x, y) = (1 / (2 * pi * sigma^2)) * exp(-(x^2 + y^2) / (2 * sigma^2))
    if (size <= 0 || size % 2 == 0) {
        throw std::invalid_argument("Gaussian blur kernel size must be positive and odd.");
    }

    KernelMatrix matrix(size, std::vector<double>(size));
    int center = (size - 1)/ 2;
    double twoSigmaSq = 2.0 * sigma * sigma;


    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int dx = col - center; // relative x coordinate to the centre 
            int dy = row - center; // relative y coordinate to the centre
            matrix[row][col] = std::exp(-(dx * dx + dy * dy) / twoSigmaSq);
        }
    }

    Kernel kernel(matrix);
    kernel.normalize(); 
    return kernel;

}

}