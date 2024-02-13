#include "Image.h"

Image::Image() : MultimediaObject() {}
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

std::string Image::classname() const {
    return "Image";
}

void Image::serialize(std::ostream & out) const {
    MultimediaObject::serialize(out);
    out << width << "\n" << height << "\n";
}

void Image::deserialize(std::istream & in) {
    MultimediaObject::deserialize(in);
    in >> width;
    in.ignore();
    in >> height;
    in.ignore();
}