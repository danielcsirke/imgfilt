#pragma once

#include <vector>
#include <stdexcept>

#include "Pixel.hpp"

class Image {
    std::vector<std::vector<Pixel>> pixels; // külső függőleges , belső vízszintes(sor)
    int width, height;
public:
    Image() = default;

    Image(int width, int height) : width(width), height(height) {
        pixels.resize(height, std::vector<Pixel>(width));
    }

    Pixel& at(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            throw std::out_of_range("Pixel coordinates out of range");
        return pixels[y][x];
    }

    const Pixel& at(int x, int y) const {
        if (x < 0 || x >= width || y < 0 || y >= height)
            throw std::out_of_range("Pixel coordinates out of range");
        return pixels[y][x];
    }
    
    void resize(int width, int height) {
        this->width = width;
        this->height = height;
        pixels.resize(height, std::vector<Pixel>(width));
    }

    int getWidth() const { return width; }

    int getHeight() const { return height; }
};