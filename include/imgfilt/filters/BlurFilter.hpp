#pragma once 

#include "IConvolutionBasedFilter.hpp"
#include "Kernel.hpp"


/*
* I'll use standard linear blur, because i have no time. but later
* there could be a change, where the user can change between
* different blurs (eg. gaussian) 
*/

class BlurFilter: public IConvolutionBasedFilter { // dont need intheritance from IFilter because IConvolutionBasedFilter inherits from there!!!!!!!
    Kernel blurKernel;
    int blurRadius;
    double blurFactor;
public:
    BlurFilter(int radius = 3, double factor = 1);
    ~BlurFilter() = default;
    void apply(Picture& pic); // obligated from IFilter
    const Kernel& kernel() const; // obligated from IConvolutionBasedFilter

    // i currently don't need getters/setters fuckYeah


};