#pragma once

#include "filt_op/IFilter.hpp"
#include "types/Image.hpp"


class ContrastBrightnessFilter : public IFilter {
    double contrastFactor = 1.0;
    double brightnessFactor = 0.0;
public:
   ContrastBrightnessFilter(double contrastFactor = 1.0, double brightnessFactor = 0.0) : contrastFactor(contrastFactor), brightnessFactor(brightnessFactor) {}
   void apply(Image& img) const override;
   ~ContrastBrightnessFilter() = default;
};