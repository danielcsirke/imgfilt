#pragma once

#include <cstdint>

class Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
public:
    Pixel(unsigned r, unsigned g, unsigned b, unsigned a = 255) : r(r), g(g), b(b), a(a) {}
    uint8_t getR() const { return r; }
    uint8_t getG() const { return g; }
    uint8_t getB() const { return b; }
    uint8_t getA() const { return a; }
    void setR(uint8_t r) { this->r = r; }
    void setG(uint8_t g) { this->g = g; }
    void setB(uint8_t b) { this->b = b; }
    void setA(uint8_t a) { this->a = a; }
    void setRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};

