#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>
#include <iostream>

class MultimediaObject {
public:
    MultimediaObject(const std::string, const std::string);  // Constructor
    MultimediaObject(); // Default constructor
    ~MultimediaObject(); // Destructor

    std::string getName() const; // Getter for name
    void setName(const std::string& newName); // Setter for name

    std::string getFilename() const; // Getter for filename
    void setFilename(const std::string& newFilename); // Setter for filename

    void print(std::ostream& out) const; // Print method

    virtual void play() const = 0; // Play method

    virtual void serialize(std::ostream & out) const; // Serialize method

    virtual void deserialize(std::istream & in); // Deserialize method

    virtual std::string classname() const = 0;

protected:
    std::string name {};
    std::string filename {};
};

#endif