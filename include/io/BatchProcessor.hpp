#pragma once

#include <string>
#include <memory>
#include <sstream>

#include "IImageHandler.hpp"
#include "filt_op/FilterPipeline.hpp"
#include "types/Image.hpp"
#include "filt_op/FilterFactory.hpp"
#include "CommandType.hpp"





class BatchProcessor{
    Image img;
    FilterPipeline pipeline;
    FilterFactory factory;
    FilterSpec spec;

    std::unique_ptr<IImageHandler> createHandlerFromExtension(const std::string& filename);
    CommandType getCommandType(const std::string& cmd);
public:
    BatchProcessor() = default;
    ~BatchProcessor() = default;

    void process(const std::string& filename);
    void handleCommand(const std::string& command, std::istringstream& args);   
};