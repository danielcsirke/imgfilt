#pragma once

#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"


class ContrastBrightnessFilter : public IFilter {
    double contrastFactor;
    double brightnessFactor;
public:
   ContrastBrightnessFilter(double contrastFactor, double brightnessFactor = 0) : contrastFactor(contrastFactor), brightnessFactor(brightnessFactor) {};
   void apply(Image& img) const override;
};