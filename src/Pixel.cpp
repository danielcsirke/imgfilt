#include "../../include/Pixel.hpp"
#include <algorithm> // for std::clamp
#include <cmath> // for std::round



// dont have to call setRGBA() with uint8_t, the program automaticly converts it. 
// i have used uint8_t because i have to store 1 byte in each variable and this is exactly what uint8_t is for. (better memory efficiency)
// needs c++17 because of std::clamp

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}

uint8_t Pixel::getR() const { return r; }
uint8_t Pixel::getG() const { return g; }
uint8_t Pixel::getB() const { return b; }
uint8_t Pixel::getA() const { return a; }
void Pixel::setR(double r) {
    this->r = static_cast<uint8_t>(
        std::clamp(static_cast<int>(std::round(r)), 0, 255)
    );
}

void Pixel::setG(double g) {
    this->g = static_cast<uint8_t>(
        std::clamp(static_cast<int>(std::round(g)), 0, 255)
    );
}

void Pixel::setB(double b) {
    this->b = static_cast<uint8_t>(
        std::clamp(static_cast<int>(std::round(b)), 0, 255)
    );
}

void Pixel::setA(double a) {
    this->a = static_cast<uint8_t>(
        std::clamp(static_cast<int>(std::round(a)), 0, 255)
    );
}

void Pixel::setGray(double gray) {
    setR(gray);
    setG(gray);
    setB(gray);
}

void Pixel::setRGBA(double r, double g, double b, double a) {
    setR(r);
    setG(g);
    setB(b);
    setA(a);
}


