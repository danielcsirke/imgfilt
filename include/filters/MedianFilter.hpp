#pragma once

#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"

class MedianFilter : public IFilter {
    uint kernelSize;

public:
    MedianFilter(unsigned kernelSize) : kernelSize(kernelSize) {}
    void apply(Image& img) const override;
};