#pragma once 

#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"
#include "types/Kernel.hpp"

class ConvolutionFilter : public IFilter {
    Kernel kernel;

public:
    ConvolutionFilter(const Kernel& kernel) : kernel(kernel) {}
    ~ConvolutionFilter() = default;
    void apply(Image& img) const override;
};