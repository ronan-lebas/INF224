#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "MultimediaObject.h"
using ObjectPtr = std::shared_ptr<MultimediaObject>;

/**
 * @brief Represents a group of objects.
 * 
 * This class inherits from std::list<ObjectPtr> and provides additional functionality
 * for managing a group of objects. Each group has a name associated with it.
 */
class Group : public std::list<ObjectPtr> {
private:
    std::string name;

public:
    /**
     * @brief Constructs a new Group object with the given name.
     * 
     * @param name The name of the group.
     */
    Group(const std::string name);

    /**
     * @brief Gets the name of the group.
     * 
     * @return The name of the group.
     */
    std::string getName() const;

    /**
     * @brief Prints the group to the specified output stream.
     * 
     * @param out The output stream to print the group to.
     */
    void print(std::ostream& out) const;
};


#endif