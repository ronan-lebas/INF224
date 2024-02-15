#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>
#include <iostream>

/**
 * @class MultimediaObject
 * @brief Represents a multimedia object with a name and a filename.
 * 
 * The MultimediaObject class provides basic functionality for managing multimedia objects.
 * It includes methods for getting and setting the name and filename, as well as printing,
 * playing, serializing, and deserializing the object.
 * 
 * This class is an abstract base class, meaning it cannot be instantiated directly.
 * Derived classes must implement the pure virtual methods play() and classname().
 */
class MultimediaObject {
public:
    /**
     * @brief Constructor for MultimediaObject.
     * @param name The name of the multimedia object.
     * @param filename The filename of the multimedia object.
     */
    MultimediaObject(const std::string, const std::string);  // Constructor

    /**
     * @brief Default constructor for MultimediaObject.
     */
    MultimediaObject(); // Default constructor

    /**
     * @brief Destructor for MultimediaObject.
     */
    ~MultimediaObject(); // Destructor

    /**
     * @brief Getter for the name of the multimedia object.
     * @return The name of the multimedia object.
     */
    std::string getName() const; // Getter for name

    /**
     * @brief Setter for the name of the multimedia object.
     * @param newName The new name of the multimedia object.
     */
    void setName(const std::string& newName); // Setter for name

    /**
     * @brief Getter for the filename of the multimedia object.
     * @return The filename of the multimedia object.
     */
    std::string getFilename() const; // Getter for filename

    /**
     * @brief Setter for the filename of the multimedia object.
     * @param newFilename The new filename of the multimedia object.
     */
    void setFilename(const std::string& newFilename); // Setter for filename

    /**
     * @brief Print the multimedia object to the specified output stream.
     * @param out The output stream to print to.
     */
    void print(std::ostream& out) const; // Print method

    /**
     * @brief Pure virtual method for playing the multimedia object.
     * 
     * Derived classes must implement this method to provide specific play functionality.
     */
    virtual void play() const = 0; // Play method

    /**
     * @brief Virtual method for serializing the multimedia object to the specified output stream.
     * @param out The output stream to serialize to.
     */
    virtual void serialize(std::ostream & out) const; // Serialize method

    /**
     * @brief Virtual method for deserializing the multimedia object from the specified input stream.
     * @param in The input stream to deserialize from.
     */
    virtual void deserialize(std::istream & in); // Deserialize method

    /**
     * @brief Pure virtual method for getting the classname of the multimedia object.
     * @return The classname of the multimedia object.
     */
    virtual std::string classname() const = 0;

protected:
    std::string name {}; ///< The name of the multimedia object.
    std::string filename {}; ///< The filename of the multimedia object.
};

#endif