#include <stdexcept>
#include <string>

class FileOpenException : public std::runtime_error {
public:
    FileOpenException(std::string msg);
};

class InvalidFormatException : public std::runtime_error {
public:
    InvalidFormatException(std::string msg);
};

class InvalidFilterParameterException : public std::runtime_error {
public:
    InvalidFilterParameterException(std::string msg);
};

class InvalidFilterTypeException : public std::runtime_error {
public:
    InvalidFilterTypeException(std::string msg);
};

