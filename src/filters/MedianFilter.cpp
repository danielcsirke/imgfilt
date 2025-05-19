#include "filters/MedianFilter.hpp"
#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"
#include <algorithm>
#include <vector>
#include <stdexcept>


MedianFilter::MedianFilter(uint kernelSize) : kernelSize(kernelSize) {
    if (kernelSize % 2 == 0) {
        throw std::invalid_argument("Kernel size must be odd.");
    }
}

// Function to convert absolute coordinates to relative coordinates
int MedianFilter::absToRel(int coordinate, int size) const {
    return coordinate - ((size - 1) / 2);
}

void MedianFilter::apply(Image& img) const {

    Image result(img.getWidth(), img.getHeight());
    int DEBUG = 0;

    // Iterate over each pixel in the image
    for (int imgRow = 0; imgRow < img.getHeight(); ++imgRow) {
        for (int imgCol = 0; imgCol < img.getWidth(); ++imgCol) {
           
            std::vector<Pixel> pixels; // Vector to store pixel values for median calculation
            Pixel median; // Variable to store the median pixel value

            for (int kernelRow = 0; kernelRow < kernelSize; ++kernelRow) {
                for (int kernelCol = 0; kernelCol < kernelSize; ++kernelCol) {

                    // Calculate the relative pixel offset
                    int yrel = absToRel(kernelRow, kernelSize);
                    int xrel = absToRel(kernelCol, kernelSize);

                    // Calculate the relative pixel position
                    int prow = imgRow + yrel; 
                    int pcol = imgCol + xrel; 

                    // Check if the pixel is within bounds                    
                    if (pcol < 0 || pcol >= img.getWidth() || prow < 0 || prow >= img.getHeight()) {
                        continue; // Skip if the pixel is out of bounds
                    }
                    
                    // Add the pixel value to the vector
                    pixels.push_back(img.at(prow, pcol)); 

                }
            }

            // Sort the pixel values to find the median
            
            // Sort by the red channel
            // std::sort(pixels.begin(), pixels.end(), [](const Pixel& a, const Pixel& b) {return a.getR() < b.getR();});
            std::nth_element(pixels.begin(), pixels.begin() + (pixels.size()-1)/2, pixels.end(), [](const Pixel& a, const Pixel& b) {return a.getR() < b.getR();});
            // Get the red median:
            median.setR(pixels[(pixels.size()-1)/2].getR());

            // Sort by the green channel
            std::nth_element(pixels.begin(), pixels.begin() + (pixels.size()-1)/2, pixels.end(), [](const Pixel& a, const Pixel& b) {return a.getG() < b.getG();});
            // Get the green median:
            median.setG(pixels[(pixels.size()-1)/2].getG());

            
            // Sort by the blue channel
            std::nth_element(pixels.begin(), pixels.begin() + (pixels.size()-1)/2, pixels.end(), [](const Pixel& a, const Pixel& b) {return a.getB() < b.getB();});
            // Get the blue median:
            median.setB(pixels[(pixels.size()-1)/2].getB());

            
            // Sort by the alpha channel
            std::nth_element(pixels.begin(), pixels.begin() + (pixels.size()-1)/2, pixels.end(), [](const Pixel& a, const Pixel& b) {return a.getA() < b.getA();});
            // Get the alpha median:
            median.setA(pixels[(pixels.size()-1)/2].getA());
            
            
            // Set the median pixel value to the result image
            result.setPixel(imgRow, imgCol, median);
        }
    }
    // Update the original image with the result
    img = result;

}

