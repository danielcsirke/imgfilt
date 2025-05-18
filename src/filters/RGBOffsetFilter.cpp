#include "filters/RGBOffsetFilter.hpp"


void RGBOffsetFilter::apply(Image& img) const {
    for (int row = 0; row < img.getHeight(); ++row) {
        for (int col = 0; col < img.getWidth(); ++col) {
            Pixel& pixel = img.at(row, col);

            pixel.setR(pixel.getR() + redOffset);
            pixel.setG(pixel.getG() + greenOffset);
            pixel.setB(pixel.getB() + blueOffset);
        }
    }
}