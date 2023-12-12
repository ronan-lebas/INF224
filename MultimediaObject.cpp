#include "MultimediaObject.h"

// Constructor
MultimediaObject::MultimediaObject(std::string name, std::string filename) : name(name), filename(filename) {}

// Destructor
MultimediaObject::~MultimediaObject() {}

// Getter for name
std::string MultimediaObject::getName() const {
    return name;
}

// Setter for name
void MultimediaObject::setName(const std::string& newName) {
    name = newName;
}

// Getter for filename
std::string MultimediaObject::getFilename() const {
    return filename;
}

// Setter for filename
void MultimediaObject::setFilename(const std::string& newFilename) {
    filename = newFilename;
}

// Print method
void MultimediaObject::print(std::ostream& out) const {
    out << "Name: " << name << std::endl;
    out << "Filename: " << filename << std::endl;
}