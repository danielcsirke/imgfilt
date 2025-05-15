#pragma once 

class ConvolutionFilter : public IFilter {
    Kernel kernel;
public:

    void apply(Image& img) const override;
    ConvolutionFilter(const Kernel& kernel) : kernel(kernel) {};
};