//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Image.h"
#include "Video.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    
    //create an Image and a Video object
    Image* img = new Image("Image", "image.jpg", 100, 200);
    Video* vid = new Video("Video", "video.mp4", 60);
    img->print(std::cout);
    vid->print(std::cout);
    return 0;
}