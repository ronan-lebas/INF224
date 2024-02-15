#include "Movie.h"

Movie::Movie() : Video() {}
Movie::Movie(std::string name, std::string filename, int duration) : Video(name, filename, duration) {}

Movie::Movie(std::string name, std::string filename, int duration, int numberOfChapters, const int * chapters) : Video(name, filename, duration), numberOfChapters(numberOfChapters) {
    setChapters(numberOfChapters, chapters);
}

Movie::Movie(const Movie &movie) : Video(movie), numberOfChapters(movie.numberOfChapters) {
    setChapters(numberOfChapters, movie.chapters);
}

Movie::~Movie()
{
    delete[] chapters;
}

int Movie::getNumberOfChapters() const
{
    return numberOfChapters;
}

int Movie::getChapter(int index) const
{
    return chapters[index];
}

const int * Movie::getChapters() const {
    return chapters;

}

void Movie::setChapters(int newNumberOfChapters, const int newChapters[])
{
    if ((newNumberOfChapters <= 0) | (newChapters == nullptr)) throw std::runtime_error("Invalid chapters.");
    else {
        delete[] chapters;
        numberOfChapters = newNumberOfChapters;
        chapters = new int[numberOfChapters];
        for (int i = 0; i < numberOfChapters; i++)
        {
            chapters[i] = newChapters[i];
        }
    }
}

void Movie::printChapter(std::ostream &out) const
{
    for (int i = 0; i < numberOfChapters; i++)
    {
        out << "Chapitre " << i << " : " << chapters[i] << ", ";
    }
}

std::string Movie::classname() const {
    return "Movie";
}

void Movie::serialize(std::ostream &out) const
{
    Video::serialize(out);
    out << numberOfChapters << "\n";
    for (int i = 0; i < numberOfChapters; i++)
    {
        out << chapters[i] << "\n";
    }
}

void Movie::deserialize(std::istream &in)
{
    Video::deserialize(in);
    in >> numberOfChapters;
    in.ignore();
    delete[] chapters;
    chapters = new int[numberOfChapters];
    for (int i = 0; i < numberOfChapters; i++)
    {
        in >> chapters[i];
        in.ignore();
    }
}