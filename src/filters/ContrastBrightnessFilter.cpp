#include "filters/ContrastBrightnessFilter.hpp"
#include "types/Image.hpp"
#include <iostream> // debugging


// A simple contrast and brightness filter 
// uses the formula: I' = c*(I - 128) + 128 + b
// where I' is the output pixel value,
// I is the input pixel value,
// c is the contrast factor
// and b is the brightness factor.
// the filter doesn't change the alpha channel

void ContrastBrightnessFilter::apply(Image& img) const {
    for (int row = 0; row < img.getHeight(); ++row) {
        for (int col = 0; col < img.getWidth(); ++col) {
            Pixel pixel = img.at(row, col);
            pixel.setRGBA(
                contrastFactor * (pixel.getR() - 128) + 128 + brightnessFactor,
                contrastFactor * (pixel.getG() - 128) + 128 + brightnessFactor,
                contrastFactor * (pixel.getB() - 128) + 128 + brightnessFactor,
                pixel.getA()
            );
            img.setPixel(row, col, pixel);
        }
    }
    
}