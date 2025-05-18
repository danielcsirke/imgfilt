#include <algorithm>
#include "types/Pixel.hpp"
#include <stdexcept>
#include "io/BMPImageHandler.hpp"
#include <fstream>
#include <cstdint>


// this function flips the image vertically regardless of the height value in the header
void BMPImageHandler::flipVertical(Image& img, BITMAPINFOHEADER& header) const {
    int width = header.width;
    int height = std::abs(header.height);

    for (int row = 0; row < height / 2; ++row) {
        for (int col = 0; col < width; ++col) {
            int oppositeRow = height - row - 1; // -1 is needed because the rows are 0-indexed
            std::swap(img.at(row, col), img.at(oppositeRow, col));

        }
    }
    header.height *= (-1); // Adjust the height to be the opposite of the original value
}




std::unique_ptr<Image> BMPImageHandler::load(const std::string& filename) const {
    // Open the file in binary mode
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open BMP file: " + filename);
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (fileHeader.fileType != 0x4D42) { // 'BM'
        throw std::runtime_error("BMP load failed: " + filename + " (bad signature)");
    }

    if (infoHeader.bitCount != 32) {
        throw std::runtime_error("Only 32-bit BMP files are supported: " + filename);
    }

    std::unique_ptr<Image> image = std::make_unique<Image>(infoHeader.width, std::abs(infoHeader.height));

    file.seekg(fileHeader.offsetData, std::ios::beg); // std::ios::beg means seeking from the beginning of the file

    for (int row = 0; row < std::abs(infoHeader.height); ++row) {
        for (int col = 0; col < infoHeader.width; ++col) {
            uint8_t blue, green, red, alpha;
            file.read(reinterpret_cast<char*>(&blue), sizeof(blue));
            file.read(reinterpret_cast<char*>(&green), sizeof(green));
            file.read(reinterpret_cast<char*>(&red), sizeof(red));
            file.read(reinterpret_cast<char*>(&alpha), sizeof(alpha));

            Pixel pixel(red, green, blue, alpha);
            image->setPixel(row, col, pixel);
        }
    }
    file.close();

    if (infoHeader.height > 0) {
        flipVertical(*image, infoHeader);
    }
    
    return image;
}



void BMPImageHandler::save(const std::string& filename, const Image& image) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open BMP file for writing: " + filename);
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    fileHeader.fileType = 0x4D42; // 'BM'
    fileHeader.fileSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + image.getWidth() * image.getHeight() * 4;
    fileHeader.reserved1 = 0;
    fileHeader.reserved2 = 0;
    fileHeader.offsetData = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    infoHeader.size = sizeof(BITMAPINFOHEADER);
    infoHeader.width = image.getWidth();
    infoHeader.height = image.getHeight();
    infoHeader.planes = 1;
    infoHeader.bitCount = 32;
    infoHeader.compression = 0; 
    infoHeader.sizeImage = image.getWidth() * image.getHeight() * 4; 
    infoHeader.xPixelsPerMeter = 0;
    infoHeader.yPixelsPerMeter = 0;
    infoHeader.colorsUsed = 0; // all colors
    infoHeader.importantColors = 0; // all colors are important


    // Write the file header
    file.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
    
    // Write pixel data
    for (int row = image.getHeight() - 1; row >= 0; --row) { // reverse order because BMP are usually stored bottom-up
        for (int col = 0; col < image.getWidth(); ++col) {
            Pixel pixel = image.at(row, col);
            uint8_t blue = static_cast<uint8_t>(std::clamp(pixel.getB(), 0.0, 255.0));
            uint8_t green = static_cast<uint8_t>(std::clamp(pixel.getG(), 0.0, 255.0));
            uint8_t red = static_cast<uint8_t>(std::clamp(pixel.getR(), 0.0, 255.0));
            uint8_t alpha = static_cast<uint8_t>(std::clamp(pixel.getA(), 0.0, 255.0));

            file.write(reinterpret_cast<char*>(&blue), sizeof(blue));
            file.write(reinterpret_cast<char*>(&green), sizeof(green));
            file.write(reinterpret_cast<char*>(&red), sizeof(red));
            file.write(reinterpret_cast<char*>(&alpha), sizeof(alpha));
        }
    }
    file.close();  
}

BMPImageHandler::~BMPImageHandler() = default;