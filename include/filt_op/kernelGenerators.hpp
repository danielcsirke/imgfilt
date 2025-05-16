#pragma once

#include "types/Kernel.hpp"

namespace kernelGenerators {

Kernel createBoxBlurKernel(int size);

Kernel createGaussianBlurKernel(int size, double sigma);

}
