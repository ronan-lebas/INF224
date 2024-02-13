#include "Group.h"

Group::Group(const std::string name) : name(name) {}

std::string Group::getName() const {
    return name;
}

void Group::print(std::ostream& out) const {
    out << name << " contains: ";
    for (ObjectPtr object : *this) {
        object->print(out);
        out << ", ";
    }
}