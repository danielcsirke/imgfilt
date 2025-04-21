// ContrastBrightnessFilter

#include "../../include/imgfilt/filters/ContrastBrightnessFilter.hpp"
#include "../../include/core/Pixel.hpp"



/*
* Usage: 
* I' = a*(I - 128) + 128 + b
* where I' is the output pixel value,
* I is the input image, 
* a is the contrast factor
* and b is the brightness factor.
* 
* It iterates through each pixel in the image,
* applies the contrast and brightness adjustments,
* and sets the new pixel value.
*/

ContrastBrightnessFilter::ContrastBrightnessFilter(double contrast, double brightness) : contrastFactor(contrast), brightnessFactor(brightness) {}

void ContrastBrightnessFilter::apply(Picture& pic) {
    for (int y = 0; y < pic.getHeight(); ++y) {
        for (int x = 0; x < pic.getWidth(); ++x) {
            Pixel tempPixel = pic.getPixel(x,y);
            tempPixel.setRGBA(
                contrastFactor * (tempPixel.getR() - 128) + 128 + brightnessFactor,
                contrastFactor * (tempPixel.getG() - 128) + 128 + brightnessFactor,
                contrastFactor * (tempPixel.getB() - 128) + 128 + brightnessFactor,
                tempPixel.getA()
            );
            pic.setPixel(x, y, tempPixel);
        }
    }
}

ContrastBrightnessFilter::~ContrastBrightnessFilter() = default;