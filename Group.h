#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "MultimediaObject.h"
using ObjectPtr = std::shared_ptr<MultimediaObject>;

class Group : public std::list<ObjectPtr> {
private:
    std::string name;

public:
    Group(const std::string name);
    std::string getName() const;
    void print(std::ostream& out) const;
};


#endif