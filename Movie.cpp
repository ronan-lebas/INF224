#include "Movie.h"

Movie::Movie(std::string name, std::string filename, int duration) : Video(name, filename, duration) {}

Movie::Movie(std::string name, std::string filename, int duration, int numberOfChapters, int * chapters) : Video(name, filename, duration), numberOfChapters(numberOfChapters), chapters(chapters) {}

Movie::~Movie() {
    delete[] chapters;
}

int Movie::getNumberOfChapters() const {
    return numberOfChapters;
}

int Movie::getChapter(int index) const {
    return chapters[index];
}

void Movie::setChapters(int newNumberOfChapters, int newChapters[]) {
    numberOfChapters = newNumberOfChapters;
    chapters = newChapters;
}

void Movie::printChapter(std::ostream& out) const {
    for (int i = 0; i < numberOfChapters; i++) {
        out << "Chapitre " << i << " : " << chapters[i] << std::endl;
    }
}