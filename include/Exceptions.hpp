#include <stdexcept>
#include <string>

class FileOpenException : public std::runtime_error {
public
    FileOpenException(std::string msg);
};

class InvalidFormatException : public std::runtime_error {
    InvalidFormatException(std::string msg);
};

class InvalidFilterParameterException : public std::runtime_error {
    InvalidFilterParameterException(std::string msg);
};

class InvalidFilterTypeException : public std::runtime_error {
    InvalidFilterTypeException(std::string msg);
};

