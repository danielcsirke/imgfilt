#pragma once 

class RGBOffsetFilter : public IFilter {
    double redOffset;
    double greenOffset;
    double blueOffset;
public:
    void apply(Image& img) const override;
    RGBOffsetFilter(const double& redOffset, const double& greenOffset, const double& blueOffset) : redOffset(redOffset), greenOffset(greenOffset), blueOffset(blueOffset) {};
};