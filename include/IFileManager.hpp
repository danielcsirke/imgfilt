#pragma once    
#include "Picture.hpp"
#include <string>

class IFileManager {
    public:
        virtual bool load (const std::string& filename, Picture& pic) = 0;
        virtual bool save (const std::string& filename, const Picture& pic) = 0;
        virtual ~IFileManager() = default;
    };