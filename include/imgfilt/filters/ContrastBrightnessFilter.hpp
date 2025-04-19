#pragma once

#include "IFilter.hpp"
#include "../../core/Pixel.hpp"
#include <cstdint>
#include <algorithm>
#include <cmath>


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
class ContrastBrightnessFilter: public IFilter {
double contrastFactor;
double brightnessFactor;
public:
    ContrastBrightnessFilter(double contrast, double brightness) : contrastFactor(contrast), brightnessFactor(brightness) {}

    void apply(Picture& pic) override {
        for (int y = 0; y < pic.getHeight(); ++y) {
            for (int x = 0; x < pic.getWidth(); ++x) {
                Pixel tempPixel = pic.getPixel(x,y);
                tempPixel.setRGBA(
                    std::clamp(static_cast<int>(std::round(contrastFactor * (tempPixel.getR() - 128) + 128 + brightnessFactor)), 0, 255),
                    std::clamp(static_cast<int>(std::round(contrastFactor * (tempPixel.getG() - 128) + 128 + brightnessFactor)), 0, 255),
                    std::clamp(static_cast<int>(std::round(contrastFactor * (tempPixel.getB() - 128) + 128 + brightnessFactor)), 0, 255),
                    tempPixel.getA()
                );
                pic.setPixel(x, y, tempPixel);
            }
        }
    }

    ~ContrastBrightnessFilter() override = default;
};

// NEM H FILEBAN ÍRUNK KÓDOT!!!! ÁTÍRNI A CPP FILEBA!!!