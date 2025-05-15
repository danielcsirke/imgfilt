#pragma once 

#include "Image.hpp"

class IFilter {
public:
    virtual ~IFilter() = default;
    virtual void apply(Image& img) const = 0;
};