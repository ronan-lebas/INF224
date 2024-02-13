#include "MultimediaObject.h"

// Constructor
MultimediaObject::MultimediaObject(std::string name, std::string filename) : name(name), filename(filename) {}
MultimediaObject::MultimediaObject() {}

// Destructor
MultimediaObject::~MultimediaObject() {
    std::cout << "MultimediaObject " << name << " destroyed" << std::endl;
}

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
    out << "Name: " << name << ", ";
    out << "Filename: " << filename;
}

// Serialize method
void MultimediaObject::serialize(std::ostream & out) const {
    out << classname() << "\n" << name << "\n" << filename << "\n";
}

// Deserialize method
void MultimediaObject::deserialize(std::istream & in) {
    std::getline(in, name);
    std::getline(in, filename);
}