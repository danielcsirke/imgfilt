#pragma once

#include <iostream>
#include "core/Picture.hpp"

class IFilter {
    public:
        virtual void apply(Picture& pic) = 0;
        virtual ~IFilter() {}
};