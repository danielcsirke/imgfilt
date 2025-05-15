#pragma once

#include <iostream>
#include <vector>

#include "Pixel.hpp"

class Image {
    std::vector<std::vector<Pixel>> pixels;
    int width, height;
public:
    Image() = default;

    Image(int width, int height) : width(width), height(height) {
        pixels.resize(height, std::vector<Pixel>(width));
    }

    Pixel& at(int x, int y) {
        return pixels[y][x];
    }

    const Pixel& at(int x, int y) const {
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