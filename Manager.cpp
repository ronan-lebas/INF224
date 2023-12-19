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
/////////////////
void Manager::print(std::ostream & out, const std::string name) const {
    auto it = objects.find(name);
    if (it != objects.end()) {
        it->second->print(out);
    } else {
        out << "Object not found." << std::endl;
    }
}

void Manager::play(const std::string name) const {
    auto it = objects.find(name);
    if (it != objects.end()) {
        it->second->play();
    } else {
        std::cout << "Object not found." << std::endl;
    }
}

void Manager::remove(const std::string name) {
    auto it = objects.find(name);
    if (it != objects.end()) {
        objects.erase(it);
    }
}
