#include "filt_op/FilterPipeline.hpp"


void FilterPipeline::apply(Image& img) {
    for (size_t i = 0; i < filters.size(); ++i) {
        filters[i]->apply(img);
    }    
}

void FilterPipeline::add(std::unique_ptr<IFilter> filter) {
    filters.push_back(std::move(filter)); 
}

void FilterPipeline::clear() {
    filters.clear();
}