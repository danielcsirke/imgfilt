#include "../../include/core/Pixel.hpp"
#include <algorithm>



// dont have to call setRGBA() with uint8_t, the program automaticly converts it. 
// i have used uint8_t because i have to store 1 byte in each variable and this is exactly what uint8_t is for. (better memory efficiency)
// needs c++17 because of std::clamp

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}

uint8_t Pixel::getR() const { return r; }
uint8_t Pixel::getG() const { return g; }
uint8_t Pixel::getB() const { return b; }
uint8_t Pixel::getA() const { return a; }
void Pixel::setR(int r) { this->r = static_cast<uint8_t>(std::clamp(r, 0, 255)); }
void Pixel::setG(int g) { this->g = static_cast<uint8_t>(std::clamp(g, 0, 255)); }
void Pixel::setB(int b) { this->b = static_cast<uint8_t>(std::clamp(b, 0, 255)); }
void Pixel::setA(int a) { this->a = static_cast<uint8_t>(std::clamp(a, 0, 255)); }
void Pixel::setRGBA(int r, int g, int b, int a) {
    this->r = static_cast<uint8_t>(std::clamp(r, 0, 255));
    this->g = static_cast<uint8_t>(std::clamp(g, 0, 255));
    this->b = static_cast<uint8_t>(std::clamp(b, 0, 255));
    this->a = static_cast<uint8_t>(std::clamp(a, 0, 255));
}


