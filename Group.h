#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <iostream>
#include <string>
#include "MultimediaObject.h"

class Group : public std::list<MultimediaObject *> {
private:
    std::string name;

public:
    Group(const std::string name);
    std::string getName() const;
    void print(std::ostream& out) const;
};


#endif