#pragma once

#include "IFilter.hpp"
#include "../../core/Picture.hpp"
#include "Kernel.hpp"


class IConvolutionBasedFilter : public IFilter {
public: 
    virtual ~IConvolutionBasedFilter() = default; // we need = default, because just because the function is default, we have to delete the virtual vector table, even if it points to nothing, if i write = 0, there will be a linker error
    virtual void applyConvolution(Picture& pic); // todo
    virtual const Kernel& kernel() const = 0;

};