#include "io/BatchProcessor.hpp"


void BatchProcessor::process(const std::string& filename) {}

void BatchProcessor::handleCommand(const std::string& command, std::istringstream& args) {
    switch(getCommandType(command)) {

        case CommandType::INPUT: {
            std::string filename;
            args >> filename;
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
            pipeline.apply(img);
            handler->save(filename, img);
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
    if (cmd == "INPUT") return CommandType::INPUT;
    else if (cmd == "OUTPUT") return CommandType::OUTPUT;
    else if (cmd == "CONTRAST") return CommandType::CONTRAST;
    else if (cmd == "BRIGHTNESS") return CommandType::BRIGHTNESS;
    else if (cmd == "BLUR") return CommandType::BLUR;
    else if (cmd == "GAUSSIAN_BLUR") return CommandType::GAUSSIAN_BLUR;
    else if (cmd == "MEDIAN") return CommandType::MEDIAN;
    else if (cmd == "RGB_OFFSET") return CommandType::RGB_OFFSET;
    else return CommandType::UNKNOWN;
}   