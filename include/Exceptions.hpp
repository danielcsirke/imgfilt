#include <stdexcept>
#include <string>

class FileOpenException : public std::runtime_error {

};

class InvalidFormatException : public std::runtime_error {

};

class InvalidFilterParameterException : public std::runtime_error {

};

class InvalidFilterTypeException : public std::runtime_error {

};

