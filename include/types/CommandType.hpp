#pragma once

enum class CommandType {
    INPUT,
    OUTPUT,
    CONTRAST,
    BRIGHTNESS,
    BLUR,
    GAUSSIAN_BLUR,
    MEDIAN,    
    RGB_OFFSET,
    UNKNOWN,
};