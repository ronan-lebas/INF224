#ifndef MOVIE_H
#define MOVIE_H


#include "Video.h"

class Movie : public Video {
public:
    Movie(std::string name, std::string filename, int duration);
    Movie(std::string name, std::string filename, int duration, int numberOfChapters, int * chapters);
    ~Movie();
    int getNumberOfChapters() const;
    int getChapter(int index) const;
    void setChapters(int newNumberOfChapters, int newChapters[]);
    void printChapter(std::ostream& out) const;

private:
    int numberOfChapters = 0;
    int * chapters = nullptr;

};
#endif