#pragma once 

#include <string>
#include <memory>

#include "IImageHandler.hpp"
#include "types/Image.hpp"



class BMPImageHandler : public IImageHandler {
public:
    BMPImageHandler() = default;
    ~BMPImageHandler() override;

    std::unique_ptr<Image> load(const std::string& filename) const override;
    void save(const std::string& filename, const Image& image) const override;
};