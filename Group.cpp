#include "Group.h"

Group::Group(const std::string name) : name(name) {}

std::string Group::getName() const {
    return name;
}

void Group::print(std::ostream& out) const {
    for (MultimediaObject * object : *this) {
        object->print(out);
    }
}