#pragma once

#include <cstdint>

class Pixel{
    uint8_t r, g, b, a;
public:
    // Constructor
    Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

    // Getters
    uint8_t getR() const;
    uint8_t getG() const;
    uint8_t getB() const;
    uint8_t getA() const;

    // Setters
    // gets int, becasue if because of an error it would be outside of the range of uint8_t, the program would not crash
    // i will use std::clamp to make sure the value is between 0 and 255
    void setR(double r);
    void setG(double g);
    void setB(double b);
    void setA(double a);
    void setGray(double gray); // sets all colors to the same value
    void setRGBA(double r, double g, double b, double a = 255);
};

