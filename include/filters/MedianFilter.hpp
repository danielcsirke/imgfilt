#pragma once

class MedianFilter : public IFilter {
    uint kernelSize;
public:
    void apply(Image& img) const override;
    MedianFilter(const uint& kernelSize) : kernelSize(kernelSize) {};
};