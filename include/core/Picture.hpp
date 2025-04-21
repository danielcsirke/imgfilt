#pragma once

#include <vector>
#include "Pixel.hpp"

class Picture {
    unsigned width, height;
    std::vector<Pixel> pixels;
public:
    Picture(unsigned width, unsigned height);
    unsigned getWidth() const;
    unsigned getHeight() const;
    const Pixel& getPixel(unsigned x, unsigned y) const;
    void setPixel(unsigned x, unsigned y, const Pixel& pixel);
};