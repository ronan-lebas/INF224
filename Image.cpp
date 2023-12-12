#include "Image.h"

Image::Image(std::string name, std::string filename, int width, int height) : MultimediaObject(name, filename), width(width), height(height) {}

Image::~Image() {
}

int Image::getWidth() const {
    return width;
}

void Image::setWidth(int newWidth) {
    width = newWidth;
}

int Image::getHeight() const {
    return height;
}

void Image::setHeight(int newHeight) {
    height = newHeight;
}


void Image::play() const {
    std::string command = "imagej " + filename + " &";
    system(command.c_str());
}