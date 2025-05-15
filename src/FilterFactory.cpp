#include <memory>

#include <filt_op/FilterFactory.hpp>
#include "KernelLibrary.hpp"
#include "filters/ContrastBrightnessFilter.hpp"
#include "filters/ConvolutionFilter.hpp"
#include "filters/MedianFilter.hpp"
#include "filters/RGBOffsetFilter.hpp"

void FilterFactory::buildFilter(FilterPipeline& pipeline, const FilterSpec& spec) {

    if (spec.hasContrast || spec.hasBrightness) {
        pipeline.add(std::make_unique<ContrastBrightnessFilter>(spec.contrastFactor, spec.brightnessFactor));
    }

try{
    if (spec.hasBlur) {
        pipeline.add(std::make_unique<ConvolutionFilter>(kernelLibrary::createBoxBlurKernel(spec.blur)));
    }
} catch (const std::invalid_argument& e) {
    std::cerr << "Error creating box blur kernel: " << e.what() << std::endl;
    return;
}

try{
    if (spec.hasGaussian) {
        pipeline.add(std::make_unique<ConvolutionFilter>(kernelLibrary::createGaussianBlurKernel(spec.gaussianBlurSize, spec.gaussianBlurSigma)));
    }
} catch (const std::invalid_argument& e) {
    std::cerr << "Error creating Gaussian blur kernel: " << e.what() << std::endl;
    return;
}

try{
    if (spec.hasMedian) {
        pipeline.add(std::make_unique<MedianFilter>(spec.medianKernelSize));
    }
} catch (const std::invalid_argument& e) {
    std::cerr << "Error creating median filter: " << e.what() << std::endl;
    return;
}

    if (spec.hasRGBOffset) {
        pipeline.add(std::make_unique<RGBOffsetFilter>(spec.rOffset, spec.gOffset, spec.bOffset));
    }
}