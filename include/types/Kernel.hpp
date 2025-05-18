#pragma once

#include <vector>

using KernelMatrix = std::vector<std::vector<double>>; 

class Kernel {
    KernelMatrix kernelValues; 

public:
    Kernel() = default; // "=default" should be always in .hpp
    Kernel(KernelMatrix values);

    double getValue(int row, int col) const;
    void set(int row, int col, double value);
    void set(const KernelMatrix& values);
    const KernelMatrix& getValues() const; 

    int centerX() const;
    int centerY() const;
    int rows() const; // height
    int cols() const; // width
    int absToRel(int coordinate, int size) const; // convert absolute coordinates to relative coordinates to the center of the kernel

    double sum() const;
    void normalize(double epsilon = 1e-6);
    bool isNormalized(double epsilon = 1e-6) const;
    void scale(double factor);
};