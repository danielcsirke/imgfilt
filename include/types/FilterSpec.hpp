#pragma once

class FilterSpec {
public:
    FilterSpec() {
        clear();
    }

    ~FilterSpec() = default;

    bool hasContrast = false;
    double contrastFactor = 0;

    bool hasBrightness = false;
    double brightnessFactor = 0;

    bool hasBlur = false;
    unsigned blur = 0; // must be odd

    bool hasGaussian = false;
    unsigned gaussianBlurSize = 0; // must be odd
    double gaussianBlurSigma = 1.0;

    bool hasMedian = false;
    unsigned medianKernelSize = 0; // must be odd

    bool hasRGBOffset = false;
    double rOffset = 0;
    double gOffset = 0;
    double bOffset = 0;

    void clear() {
        hasContrast = false;
        contrastFactor = 0;

        hasBrightness = false;
        brightnessFactor = 0;

        hasBlur = false;
        blur = 0;

        hasGaussian = false;
        gaussianBlurSize = 0;
        gaussianBlurSigma = 0;

        hasMedian = false;
        medianKernelSize = 0;

        hasRGBOffset = false;
        rOffset = gOffset = bOffset = 0;
    }
};
