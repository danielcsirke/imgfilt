#include <stdexcept>
#include "Exceptions.hpp"
#include "BMPFileManager.hpp"
#include "Picture.hpp"
#include <fstream>
#include <iostream>



void BMPFileManager::load(const std::string& filename, Picture& pic) {

    // Open the file in binary mode
    std::ifstream picFile(filename, std::ios::binary);
    if (!picFile.good()) {
        throw FileOpenException("Hiba a file megnyitása közben: " + filename);
    }

    // Validating the BMP file
    picFile.seekg(0);
    uint16_t bfType;
    picFile.read((char*)&bfType, 2);
    if (bfType != 0x4d42)
        throw InvalidFormatException("Nem megfelelő típusú bemeneti file: " + filename);


} 

void BMPFileManager::save(const std::string& filename, const Picture& pic) {
    // TODO FILE SAVE
}

