#include <memory>
#include <iostream>

#include "filt_op/kernelGenerators.hpp"
#include "filt_op/FilterFactory.hpp"
#include "filters/ContrastBrightnessFilter.hpp"
#include "filters/ConvolutionFilter.hpp"
#include "filters/MedianFilter.hpp"
#include "filters/RGBOffsetFilter.hpp"

void FilterFactory::buildFilter(FilterPipeline& pipeline, const FilterSpec& spec) {

    if (spec.hasContrast || spec.hasBrightness) {
        pipeline.add(std::make_unique<ContrastBrightnessFilter>(spec.contrastFactor, spec.brightnessFactor));
    }

    if (spec.hasBlur) {
        try{
            pipeline.add(std::make_unique<ConvolutionFilter>(kernelGenerators::createBoxBlurKernel(spec.blur)));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error creating box blur kernel: " << e.what() << std::endl;
            return;
        }
    }

    if (spec.hasGaussian) {
        try{
            pipeline.add(std::make_unique<ConvolutionFilter>(kernelGenerators::createGaussianBlurKernel(spec.gaussianBlurSize, spec.gaussianBlurSigma)));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error creating Gaussian blur kernel: " << e.what() << std::endl;
            return;
        }
    }

    if (spec.hasMedian) {
        try{
            pipeline.add(std::make_unique<MedianFilter>(spec.medianKernelSize));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error creating median filter: " << e.what() << std::endl;
            return;
        }
    }

    if (spec.hasRGBOffset) {
        pipeline.add(std::make_unique<RGBOffsetFilter>(spec.rOffset, spec.gOffset, spec.bOffset));
    }
}