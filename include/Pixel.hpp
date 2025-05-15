#pragma once

class Pixel {
    double r, g, b, a;

public:
    Pixel(double r = 0, double g = 0, double b = 0, double a = 255)
        : r(r), g(g), b(b), a(a) {}

    double getR() const { return r; }
    double getG() const { return g; }
    double getB() const { return b; }
    double getA() const { return a; }

    void setR(double value) { r = value; }
    void setG(double value) { g = value; }
    void setB(double value) { b = value; }
    void setA(double value) { a = value; }
};
