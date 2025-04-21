#include "../../include/core/Picture.hpp"

Picture::Picture(unsigned width, unsigned height) : width(width), height(height), pixels(width * height) {}

unsigned Picture::getWidth() const { return width; } 

unsigned Picture::getHeight() const { return height; }

const Pixel& Picture::getPixel(unsigned x, unsigned y) const { return pixels[y * width + x]; }

void Picture::setPixel(unsigned x, unsigned y, const Pixel& pixel) { pixels[y * width + x] = pixel; }

