#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <stdexcept>
#include <memory>
#include <unordered_map>

#include "io/BatchProcessor.hpp"
#include "io/IImageHandler.hpp"
#include "filt_op/FilterPipeline.hpp"
#include "types/Image.hpp"
#include "filt_op/FilterFactory.hpp"
#include "io/BMPImageHandler.hpp"


/*
    process():
    Opens the text command file 
    Reads it line by line
    For each line, parses and delegated to handleCommand 
    Applies commands, updates internal state.
*/

void BatchProcessor::process(const std::string& filename) {

    std::ifstream file(filename);
 
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }


    std::string line;
    while (std::getline(file, line)) { // Read each line from the file
        std::istringstream iss(line); // Create a string stream from the line
        std::string command; // Read the first word as the command
        iss >> command; // Read the first word as the command

        if (command.empty()) continue; // Skip empty lines
        if (command[0] == '#') continue; // Skip comments

        if (command == "MOL") { // long live and prosper our Savior
            std::cout << "Soká éljen a MOL és leányvállalatai!" << std::endl;
            continue;
        }

        try{
        handleCommand(command, iss); // Handle the command
        } catch (const std::exception& e) {
            std::cerr << "Error processing command: " << line << " - " << e.what() << std::endl;
        }
    }

}

void BatchProcessor::handleCommand(const std::string& command, std::istringstream& args) {
    switch(getCommandType(command)) {

        case CommandType::INPUT: {
            std::string filename;
            args >> filename;
            if (filename.empty()) 
                throw std::runtime_error("No filename provided for INPUT command.");
            auto handler = createHandlerFromExtension(filename);
            img = handler->load(filename);
            pipeline.clear();
            spec.clear();
            break;
        }

        case CommandType::OUTPUT: {
            std::string filename;
            args >> filename;
            auto handler = createHandlerFromExtension(filename);
            factory.buildFilter(pipeline, spec);
            if (!img) 
                throw std::runtime_error("No image loaded. Use INPUT before OUTPUT.");
            pipeline.apply(*img);
            handler->save(filename, *img);
            break;
        }

        case CommandType::BRIGHTNESS: {
            args >> spec.brightnessFactor;
            spec.hasBrightness = true;
            break;
        }

        case CommandType::CONTRAST: {
            args >> spec.contrastFactor;
            spec.hasContrast = true;
            break;
        }

        case CommandType::BLUR: {
            args >> spec.blur;
            spec.hasBlur = true;
            break;
        }

        case CommandType::GAUSSIAN_BLUR: {
            args >> spec.gaussianBlurSize >> spec.gaussianBlurSigma;
            spec.hasGaussian = true;
            break;
        }

        case CommandType::MEDIAN: {
            args >> spec.medianKernelSize;
            spec.hasMedian = true;
            break;
        }

        case CommandType::RGB_OFFSET: {
            spec.hasRGBOffset = true;
            args >> spec.rOffset >> spec.gOffset >> spec.bOffset;
            break;
        }

        case CommandType::UNKNOWN:
        default:
            std::cerr << "Unknown command: " << command << std::endl;
            break;
    }

}

CommandType BatchProcessor::getCommandType(const std::string& cmd) {

    static const std::unordered_map<std::string, CommandType> commandMap = {
        {"INPUT", CommandType::INPUT},
        {"OUTPUT", CommandType::OUTPUT},
        {"CONTRAST", CommandType::CONTRAST},
        {"BRIGHTNESS", CommandType::BRIGHTNESS},
        {"BLUR", CommandType::BLUR},
        {"GAUSSIAN_BLUR", CommandType::GAUSSIAN_BLUR},
        {"MEDIAN", CommandType::MEDIAN},
        {"RGB_OFFSET", CommandType::RGB_OFFSET}
    };

    auto it = commandMap.find(cmd); // Find the command in the map
    if (it != commandMap.end()) {   // If found, return the corresponding CommandType
        return it->second;
    }

    return CommandType::UNKNOWN; // If not found, return UNKNOWN

}   

std::unique_ptr<IImageHandler> BatchProcessor::createHandlerFromExtension(const std::string& filename){
    size_t dotPos = filename.find_last_of("."); // Find the last dot's position in the filename
    if (dotPos == std::string::npos) { //If no dot is found, throw an error
        throw std::runtime_error("No file extension found in: " + filename);
    }
    std::string extension = filename.substr(dotPos + 1); //if the dot is found, extract the substring after the dot

    if (extension == "bmp" || extension == "BMP") // Check if the extension is "bmp" or "BMP"
        return std::make_unique<BMPImageHandler>(); 
    else 
        throw std::runtime_error("Unsupported file format: " + filename);
}