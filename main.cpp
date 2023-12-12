//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    
    //create a few MultimediaObject
    MultimediaObject * obj = new MultimediaObject("obj1", "obj1.mp4");
    MultimediaObject * obj2 = new MultimediaObject("obj2", "obj2.mp4");
    obj->print(cout);
    obj2->print(cout);
    
    return 0;
}