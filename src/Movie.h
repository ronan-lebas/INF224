#ifndef MOVIE_H
#define MOVIE_H


#include "Video.h"

class Movie : public Video {
public:
    Movie(std::string name, std::string filename, int duration);
    Movie(std::string name, std::string filename, int duration, int numberOfChapters, const int * chapters);
    Movie(const Movie& movie);
    ~Movie();
    int getNumberOfChapters() const;
    int getChapter(int index) const;
    const int * getChapters() const;
    void setChapters(int newNumberOfChapters, const int newChapters[]);
    void printChapter(std::ostream& out) const;

private:
    int numberOfChapters = 0;
    int * chapters = nullptr;

};
#endif