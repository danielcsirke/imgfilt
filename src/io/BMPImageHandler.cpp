#include <cstdint>
#include <algorithm>
#include "types/Pixel.hpp"



#include "io/BMPImageHandler.hpp"



void BMPImageHandler::save(const std::string& filename, const Image& image) const {

    
    // pixel values clamping:

    int x= 0, y= 0; // just placeholder values for demonstration
    Pixel p = image.at(x, y);

    uint8_t red   = static_cast<uint8_t>(std::clamp(p.getR(), 0.0, 255.0));
    uint8_t green = static_cast<uint8_t>(std::clamp(p.getG(), 0.0, 255.0));
    uint8_t blue  = static_cast<uint8_t>(std::clamp(p.getB(), 0.0, 255.0));
    
       
}

BMPImageHandler::~BMPImageHandler() = default;

std::unique_ptr<Image> BMPImageHandler::load(const std::string& filename) const {
    // TODO: Implement BMP loading logic

    // For now, return a nullptr to indicate that loading is not implemented
    return nullptr;
    
    
}