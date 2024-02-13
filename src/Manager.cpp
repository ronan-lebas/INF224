#include "Manager.h"

ObjectPtr Manager::createImage(const std::string name, const std::string filename, const int width, const int height) {
    ObjectPtr image(new Image(name, filename, width, height));
    objects[name] = image;
    return image;
}

ObjectPtr Manager::createVideo(const std::string name, const std::string filename, const int duration) {
    ObjectPtr video(new Video(name, filename, duration));
    objects[name] = video;
    return video;
}

ObjectPtr Manager::createMovie(const std::string name, const std::string filename, const int duration, const int chaptersNumber, const int * chapters) {
    ObjectPtr movie(new Movie(name, filename, duration, chaptersNumber, chapters));
    objects[name] = movie;
    return movie;
}

GroupPtr Manager::createGroup(const std::string name) {
    GroupPtr group(new Group(name));
    groups[name] = group;
    return group;
}

void Manager::printObject(std::ostream & out, const std::string name) const {
    auto it = objects.find(name);
    if (it != objects.end()) {
        it->second->print(out);
    } else {
        out << "Object not found.";
    }
}

void Manager::printAllObjects(std::ostream & out) const {
    for (auto it = objects.begin(); it != objects.end(); it++) {
        out << "Object:" << std::endl;
        it->second->print(out);
        out << std::endl;
    }
}

void Manager::printGroup(std::ostream & out, const std::string name) const {
    auto it = groups.find(name);
    if (it != groups.end()) {
        it->second->print(out);
    } else {
        out << "Group not found.";
    }
}

void Manager::play(const std::string name) const {
    auto it = objects.find(name);
    if (it != objects.end()) {
        it->second->play();
    } else {
        std::cout << "Object not found.";
    }
}

void Manager::remove(const std::string name) {
    for (auto it = objects.begin(); it != objects.end(); it++) {
        if (it->first == name) {
            for (auto it2 = groups.begin(); it2 != groups.end(); it2++) {
                it2->second->remove(it->second);
            }
            break;
        }
    }
}

bool Manager::saveObjects(std::string filename) const {
    
    std::ofstream f(filename);

    if(!f) {
        std::cerr << "Error opening file " << filename << std::endl;
        return false;
    }
    
    for (auto it = objects.begin(); it != objects.end(); it++) {
        it->second->serialize(f);
        if(f.fail()) {
            std::cerr << "Error writing to file " << filename << std::endl;
            return false;
        }
    }
    f.close();
    return true;
}

bool Manager::readObjects(std::string filename) {

    objects.clear();
    std::ifstream f(filename);

    if(!f) {
        std::cerr << "Error opening file " << filename << std::endl;
        return false;
    }

    while(f){
        std::string classname;
        getline(f, classname);
        if (classname == "") break;
        ObjectPtr object = createObject(classname);
        object->deserialize(f);
        if(f.fail()) {
            std::cerr << "Error reading from file " << filename << std::endl;
            object.reset();
            return false;
        }
        objects[object->getName()] = object;
    }
    f.close();
    return true;
}

ObjectPtr Manager::createObject(std::string classname) const {
    if (classname == "Image") {
        return ObjectPtr(new Image());
    } else if (classname == "Video") {
        return ObjectPtr(new Video());
    } else if (classname == "Movie") {
        return ObjectPtr(new Movie());
    } else {
        std::cout << "Class not found." << std::endl;
        return nullptr;
    }
}