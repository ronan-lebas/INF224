//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Image.h"
#include "Video.h"
#include "Movie.h"
#include "Group.h"
#include "Manager.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "-----Test du manager-----" << std::endl;
    Manager * manager = new Manager();

    ObjectPtr image =  manager->createImage("Image", "image.jpg", 100, 200);
    ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
    ObjectPtr image2 = manager->createImage("Image2", "image2.jpg", 100, 200);
    ObjectPtr video2 = manager->createVideo("Video2", "video2.mp4", 60);
    GroupPtr group = manager->createGroup("Groupe de test");
    group->push_back(image);
    group->push_back(video);

    manager->printObject(std::cout, "Image");
    manager->printObject(std::cout, "Video");
    manager->printObject(std::cout, "Image2");
    manager->printObject(std::cout, "Video2");
    manager->printGroup(std::cout, "Groupe de test");
    manager->play("Image");
    manager->play("Video");
    manager->remove("Image");
    manager->remove("Video");
    group->print(std::cout);

    return 0;
}