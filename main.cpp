//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Image.h"
#include "Video.h"
#include "Movie.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    

    int number = 5;
    MultimediaObject ** objects = new MultimediaObject*[number];

    objects[0] = new Image("Image", "image.jpg", 100, 200);
    objects[1] = new Video("Video", "video.mp4", 60);
    objects[2] = new Image("Image2", "image2.jpg", 100, 200);
    objects[3] = new Video("Video2", "video2.mp4", 60);
    objects[4] = new Image("Image3", "image3.jpg", 100, 200);

    for(int i=0; i<number; i++){
        objects[i]->print(std::cout);
    }

    std::cout << "Film :" << std::endl;

    int chapters[3] = {10, 20, 30};
    Movie * movie = new Movie("Movie", "movie.mp4", 120, 3, chapters);
    movie->print(std::cout);
    movie->printChapter(std::cout);

    return 0;
}