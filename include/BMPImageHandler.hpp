#pragma once 
#include "IImageHandler.hpp"
#include <string>
#include "Image.hpp"



class BMPImageHandler : public IImageHandler {
public:
    BMPImageHandler() = default;
    ~BMPImageHandler() override = default;

    Image load(const std::string& filename) const override;
    void save(const std::string& filename, const Image& image) const override;
};