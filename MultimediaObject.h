#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>
#include <iostream>

class MultimediaObject {
public:
    MultimediaObject(std::string, std::string);  // Constructor
    ~MultimediaObject(); // Destructor

    std::string getName() const; // Getter for name
    void setName(const std::string& newName); // Setter for name

    std::string getFilename() const; // Getter for filename
    void setFilename(const std::string& newFilename); // Setter for filename

    void print(std::ostream& out) const; // Print method

private:
    std::string name;
    std::string filename;
};

#endif