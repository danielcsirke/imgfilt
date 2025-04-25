#pragma once

#include "IFilter.hpp"
#include "../../core/Picture.hpp"
#include "Kernel.hpp"

/*
* This filter was made, to replace all:
* - Blur
* - EdgeDetection
* - (Sharpen) this is not incuded in tasks
* I have deleted these classes, because those will be represented by this class.
* (blur filter haven't been deleted yet, because knowledge written there should be imolemented here)
* this class was written as an interface for n earlier version of the program, so has to be extended
*/


class ConvolutionBasedFilter : public IFilter {
public: 
    virtual ~ConvolutionBasedFilter() = default; // we need = default, because just because the function is default, we have to delete the virtual vector table, even if it points to nothing, if i write = 0, there will be a linker error
    virtual void applyConvolution(Picture& pic); // todo
    virtual const Kernel& kernel() const = 0;

};