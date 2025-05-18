#pragma once

#include <vector>
#include <stdexcept>

#include "Pixel.hpp"

class Image {
    std::vector<std::vector<Pixel>> pixels; // pixels[row][col] - when writing pixels[row] it gives you a row
    int width, height;
public:
    Image() = default;

    Image(int width, int height) : width(width), height(height) {
        pixels.resize(height, std::vector<Pixel>(width));
    }

    const Pixel& at(int row, int col) const { // works on constant objects
        if (row < 0 || row >= height || col < 0 || col >= width)
            throw std::out_of_range("Pixel coordinates out of range");
        return pixels[row][col];
    }
    
    Pixel& at(int row, int col) {
        if (row < 0 || row >= height || col < 0 || col >= width)
            throw std::out_of_range("Pixel coordinates out of range");
        return pixels[row][col];
    }

    void resize(int width, int height) {
        this->width = width;
        this->height = height;
        pixels.resize(height, std::vector<Pixel>(width));
    }

    void setPixel(int row, int col, const Pixel& pixel) {
        if (row < 0 || row >= height || col < 0 || col >= width)
            throw std::out_of_range("Pixel coordinates out of range");
        pixels[row][col] = pixel;
    }

    int getWidth() const { return width; }

    int getHeight() const { return height; }
};