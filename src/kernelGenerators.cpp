#include "types/Kernel.hpp"
#include <cmath>
#include <stdexcept>
#include <vector>

namespace kernelGenerators{

Kernel createBoxBlurKernel(int size) {
    if (size <= 0 || size % 2 == 0) {
        throw std::invalid_argument("Box blur kernel size must be positive and odd.");
    }

    double value = 1.0 / (size * size);
    KernelMatrix matrix(size, std::vector<double>(size, value));

    Kernel kernel(matrix);
    kernel.normalize(); 
    return kernel;
}


Kernel createGaussianBlurKernel(int size, double sigma) {
    if (size <= 0 || size % 2 == 0) {
        throw std::invalid_argument("Gaussian blur kernel size must be positive and odd.");
    }

    KernelMatrix matrix(size, std::vector<double>(size));
    int center = size / 2;
    double twoSigmaSq = 2.0 * sigma * sigma;

    double sum = 0.0;

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            int dx = x - center;
            int dy = y - center;
            double g = std::exp(-(dx * dx + dy * dy) / twoSigmaSq);
            matrix[y][x] = g;
            sum += g;
        }
    }

    Kernel kernel(matrix);
    kernel.normalize(); 
    return kernel;

}

}