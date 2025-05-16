#pragma once 

#include "types/Image.hpp"

// Interface for image filters used in FilterPipeline

class IFilter {
public:
    virtual ~IFilter() = default;
    virtual void apply(Image& img) const = 0;
};