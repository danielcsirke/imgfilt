#include "filters/ConvolutionFilter.hpp"
#include "types/Image.hpp"
#include "types/Kernel.hpp"
#include <algorithm>



void ConvolutionFilter::apply(Image& img) const {

    Image result(img.getWidth(), img.getHeight());

    // Iterate over each pixel in the image
    for (int imgRow = 0; imgRow < img.getHeight(); ++imgRow) {

        for (int imgCol = 0; imgCol < img.getWidth(); ++imgCol) {
            Pixel sum(0,0,0,0); // Initialize sum to zero

            // Apply the kernel to the pixel
            // Iterate over the kernel
            for (int kernelRow = 0; kernelRow < kernel.rows(); ++kernelRow) {
                for (int kernelCol = 0; kernelCol < kernel.cols(); ++kernelCol) {
                    int yrel = kernel.absToRel(kernelRow, kernel.rows());
                    int xrel = kernel.absToRel(kernelCol, kernel.cols());

                    int prow = imgRow + yrel; // Calculate the relative pixel position
                    int pcol = imgCol + xrel; // Calculate the relative pixel position

                    // Check if the pixel is within bounds
                    

                    if (pcol < 0 || pcol >= img.getWidth() || prow < 0 || prow >= img.getHeight()) {
                        continue; // Skip if the pixel is out of bounds
                    }

                    sum += img.at(prow, pcol) * kernel.getValue(kernelRow, kernelCol); // Multiply the pixel value by the kernel value and add to sum
                }
            }

            result.setPixel(imgRow, imgCol, sum);
        }
    }

    img = result;
}
