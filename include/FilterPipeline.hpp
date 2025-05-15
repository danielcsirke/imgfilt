#pragma once

#include <vector>
#include <memory>

#include "Image.hpp"
#include "IFilter.hpp"

class FilterPipeline {
    std::vector<std::unique_ptr<IFilter>> filters;

public:
    FilterPipeline() = default;
    ~FilterPipeline() = default;

    void apply(Image& img);
    void add(std::unique_ptr<IFilter> filter);
    void clear();
};
