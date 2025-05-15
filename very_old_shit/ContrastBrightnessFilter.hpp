#pragma once

#include "IFilter.hpp"
#include "../../core/Picture.hpp"



class ContrastBrightnessFilter: public IFilter {
    double contrastFactor, brightnessFactor;
public:
    ContrastBrightnessFilter(double contrast, double brightness);
    void apply(Picture& pic) override;
    ~ContrastBrightnessFilter() override;
};



