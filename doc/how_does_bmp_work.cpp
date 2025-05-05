- always start with the B and M characters (0x42, 0x4D) 
    - check wether this is true - if it is, then the file is a valid BMP file (error handleing) (check wether i get a valid filetype)
- the offset is 10 bytes - the code: "seek(10)" this moves the file pointer to the right place for reading where the file starts
    - after reading in the  offset value jump to the start of the pixels

    - question: how do i know how much to read for the size of the picture (what type variable does it?)

TODO:
    - get how much we want to read in - the end of the file consists of smth else

Infos:
    - nem számít mivel nincs olyan filterem (forgatni nem akarok) hogy a kép fejjel lefel vagy rendesen van 
    - 


Egy ai példa:
==============

struct Pixel {
    uint8_t r, g, b, a; // 32 bit: 4x8
};

Picture::Picture(int width, int height, std::vector<Pixel>&& pixels)
    : width(width), height(height), data(std::move(pixels)) {}

#include <fstream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include "Picture.hpp"
#include "Exceptions.hpp"

Picture BMPFileManager::load(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw FileOpenException("Could not open file: " + filename);
    }

    // Check 'BM' signature
    char signature[2];
    file.read(signature, 2);
    if (signature[0] != 'B' || signature[1] != 'M') {
        throw InvalidFormatException("Not a valid BMP file: missing 'BM' header");
    }

    // Read pixel data offset (byte 10–13)
    file.seekg(10);
    uint32_t pixelOffset;
    file.read(reinterpret_cast<char*>(&pixelOffset), 4);

    // Read width and height (bytes 18–25)
    file.seekg(18);
    int32_t width = 0, height = 0;
    file.read(reinterpret_cast<char*>(&width), 4);
    file.read(reinterpret_cast<char*>(&height), 4);

    if (width <= 0 || height <= 0) {
        throw InvalidFormatException("Invalid image dimensions.");
    }

    // Read bits per pixel (bytes 28–29)
    file.seekg(28);
    uint16_t bpp = 0;
    file.read(reinterpret_cast<char*>(&bpp), 2);

    if (bpp != 32) {
        throw InvalidFormatException("Only 32-bit BMP files are supported.");
    }

    // Jump to pixel data
    file.seekg(pixelOffset);

    // Read pixel data
    size_t pixelCount = static_cast<size_t>(width) * height;
    std::vector<Pixel> pixels(pixelCount);

    file.read(reinterpret_cast<char*>(pixels.data()), pixelCount * sizeof(Pixel));
    if (file.fail()) {
        throw FileOpenException("Failed to read pixel data.");
    }

    return Picture(width, height, std::move(pixels));
}


