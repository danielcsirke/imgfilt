#pragma once 

#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"


class RGBOffsetFilter : public IFilter {
    double redOffset;
    double greenOffset;
    double blueOffset;

public:
    RGBOffsetFilter(double redOffset, double greenOffset, double blueOffset) : redOffset(redOffset), greenOffset(greenOffset), blueOffset(blueOffset) {}
    void apply(Image& img) const override;   
    ~RGBOffsetFilter() = default;
};