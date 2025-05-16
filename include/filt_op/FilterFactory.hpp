#pragma once

#include "FilterPipeline.hpp"
#include "types/FilterSpec.hpp"

class FilterFactory {
public:
    static void buildFilter(FilterPipeline& pipeline, const FilterSpec& spec);
};