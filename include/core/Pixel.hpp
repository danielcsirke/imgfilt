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
    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setA(int a);
    void setRGBA(int r, int g, int b, int a = 255);
};

