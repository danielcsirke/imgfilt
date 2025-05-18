#pragma once

#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"

class MedianFilter : public IFilter {
    uint kernelSize; // the size of the kernel is kernelSize x kernelSize, it alway has to be odd!

public:
    MedianFilter(unsigned kernelSize);
    void apply(Image& img) const override;
    ~MedianFilter() = default;
    int absToRel(int coordinate, int size) const;

};