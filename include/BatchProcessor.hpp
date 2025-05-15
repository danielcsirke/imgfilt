#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include "IImageHandler.hpp"
#include "FilterPipeline.hpp"
#include "Image.hpp"





class BatchProcessor{
    Image img;
    FilterPipeline pipeline;

    std::unique_ptr<IImageHandler> createHandlerFromExtension(const std::string& filename);
public:
    BatchProcessor() = default;
    ~BatchProcessor() = default;

    void process(const std::string& filename);
    void handleCommand(const std::string& command, std::istringstream& args);   
};