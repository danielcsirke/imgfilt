#pragma once
#include "types/Image.hpp"
#include <string>

class IImageHandler {
public:
    virtual ~IImageHandler() = default;
    virtual std::unique_ptr<Image> load(const std::string& filename) const = 0;
    virtual void save(const std::string& filename, const Image& image) const = 0;
};