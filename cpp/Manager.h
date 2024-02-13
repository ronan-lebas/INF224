#ifndef MANAGER_H
#define MANAGER_H
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include "MultimediaObject.h"
#include "Group.h"
#include "Image.h"
#include "Video.h"
#include "Movie.h"

using ObjectPtr = std::shared_ptr<MultimediaObject>;
using GroupPtr = std::shared_ptr<Group>;

class Manager {
    private:
        std::map<std::string, ObjectPtr> objects;
        std::map<std::string, GroupPtr> groups;

    public:
        ObjectPtr createImage(const std::string name, const std::string filename, const int width, const int height);
        ObjectPtr createVideo(const std::string name, const std::string filename, const int duration);
        ObjectPtr createMovie(const std::string name, const std::string filename, const int duration, const int chaptersNumber, const int * chapters);
        GroupPtr createGroup(const std::string name);
        void printObject(std::ostream & out, const std::string name) const;
        void printAllObjects(std::ostream & out) const;
        void printGroup(std::ostream & out, const std::string name) const;
        void play(const std::string name) const;
        void remove(const std::string name);
        bool saveObjects(std::string filename) const;
        bool readObjects(std::string filename);
        ObjectPtr createObject(std::string classname) const;
        bool checkNames(std::string name) const;

};

#endif