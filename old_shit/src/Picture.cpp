#include "Picture.hpp"
#include <stdexcept>

Picture::Picture(int32_t width, int32_t height) : width(width), height(height), pixels(width * height) {}

int32_t Picture::getWidth() const { return width; } 

int32_t Picture::getHeight() const { return height; }

const Pixel& Picture::getPixel(int32_t x, int32_t y) const { 
    if (x < 0 || x >= width || y < 0 || y >= height)
    throw std::out_of_range("Képen kívüli pixel elérésére tett kísérlet");
    return pixels[y * width + x]; 
}

void Picture::setPixel(int32_t x, int32_t y, const Pixel& pixel) { pixels[y * width + x] = pixel; }


