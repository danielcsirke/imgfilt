#pragma once

#include <vector>
#include "Pixel.hpp"
#include <cstdint>

// usage of int32_t because the width and height are stored as 32 bit integers according to the bmp format 
class Picture {
    int32_t width, height;
    std::vector<Pixel> pixels;
public:
    Picture(int32_t width, int32_t height);

    int32_t getWidth() const;
    int32_t getHeight() const;
    
    const Pixel& getPixel(int32_t x, int32_t y) const;
    void setPixel(int32_t x, int32_t y, const Pixel& pixel);
};

