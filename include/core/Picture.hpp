#pragma once

#include <iostream>
#include <vector>
#include "Pixel.hpp"




class Picture {
    unsigned width;
    unsigned height;
    std::vector<Pixel> pixels;
public:
    Picture(unsigned width, unsigned height) : width(width), height(height), pixels(width * height) {}
    unsigned getWidth() const { return width; } 
    unsigned getHeight() const { return height; }
    const Pixel& getPixel(unsigned x, unsigned y) const { return pixels[y * width + x]; }
    void setPixel(unsigned x, unsigned y, const Pixel& pixel) { pixels[y * width + x] = pixel; }
};

