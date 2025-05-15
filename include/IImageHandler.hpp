#pragma once
#include "Image.hpp"
#include <string>

class IImageHandler {
public:
    virtual ~IImageHandler() = default;
    virtual Image load(const std::string& filename) const = 0;
    virtual void save(const std::string& filename, const Image& image) const = 0;
};