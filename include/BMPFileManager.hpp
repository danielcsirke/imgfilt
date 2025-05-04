#pragma once
#include <string>
#include <stdexcept>
#include "IFileManager.hpp"
#include "Picture.hpp"
#include "Exceptions.hpp"


/*
* Validates BMP format: 32-bit, uncompressed
* Throws FileOpenException or InvalidFormatException if invalid
*
*/

class BMPFileManager : public IFileManager {
public:
    void load(const std::string& filename, Picture& pic) override;
    void save(const std::string& filename, const Picture& pic) override;
};
    
