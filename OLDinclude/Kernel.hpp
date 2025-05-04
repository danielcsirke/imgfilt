#pragma once

#include <vector>


/*
* I won't bitch around with even sized kernels, fuck even sized ones. 
* there will be a requirement, that just odd sized kernels can be used.
* because i have to fucking error handle, i have to check runtime, 
* if some stupid bitch would want to create an odd sized kernel...!! 
*/

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

    int width() const;
    int height() const;
    int centerX() const;
    int centerY() const;
    int rows() const;  // = height() MAYBE REMOVE IN THE FUTURE
    int cols() const;  // = width() MAYBE REMOVE IN THE FUTURE


    double sum() const;
    void normalize(double epsilon = 1e-6);
    bool isNormalized(double epsilon = 1e-6) const;
    void scale(double factor);

};