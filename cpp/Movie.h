#ifndef MOVIE_H
#define MOVIE_H


#include "Video.h"

/**
 * @class Movie
 * @brief Represents a movie that inherits from the Video class.
 * 
 * The Movie class provides functionality to store and manipulate information about a movie,
 * including its name, filename, duration, number of chapters, and chapter details.
 * It also overrides the classname(), serialize(), and deserialize() methods from the Video class.
 */
class Movie : public Video {
public:
    /**
     * @brief Default constructor for the Movie class.
     */
    Movie();

    /**
     * @brief Constructor for the Movie class.
     * @param name The name of the movie.
     * @param filename The filename of the movie.
     * @param duration The duration of the movie in minutes.
     */
    Movie(std::string name, std::string filename, int duration);

    /**
     * @brief Constructor for the Movie class.
     * @param name The name of the movie.
     * @param filename The filename of the movie.
     * @param duration The duration of the movie in minutes.
     * @param numberOfChapters The number of chapters in the movie.
     * @param chapters An array of integers representing the chapter details.
     */
    Movie(std::string name, std::string filename, int duration, int numberOfChapters, const int * chapters);

    /**
     * @brief Copy constructor for the Movie class.
     * @param movie The movie object to be copied.
     */
    Movie(const Movie& movie);

    /**
     * @brief Destructor for the Movie class.
     */
    ~Movie();

    /**
     * @brief Get the number of chapters in the movie.
     * @return The number of chapters.
     */
    int getNumberOfChapters() const;

    /**
     * @brief Get the chapter at the specified index.
     * @param index The index of the chapter.
     * @return The chapter at the specified index.
     */
    int getChapter(int index) const;

    /**
     * @brief Get a pointer to the array of chapters.
     * @return A pointer to the array of chapters.
     */
    const int * getChapters() const;

    /**
     * @brief Set the chapters of the movie.
     * @param newNumberOfChapters The new number of chapters.
     * @param newChapters An array of integers representing the new chapter details.
     */
    void setChapters(int newNumberOfChapters, const int newChapters[]);

    /**
     * @brief Print the chapter details to the specified output stream.
     * @param out The output stream to print to.
     */
    void printChapter(std::ostream& out) const;

    /**
     * @brief Get the classname of the movie.
     * @return The classname.
     */
    std::string classname() const override;

    /**
     * @brief Serialize the movie object to the specified output stream.
     * @param out The output stream to serialize to.
     */
    void serialize(std::ostream & out) const override;

    /**
     * @brief Deserialize the movie object from the specified input stream.
     * @param in The input stream to deserialize from.
     */
    void deserialize(std::istream & in) override;

private:
    int numberOfChapters = 0; /**< The number of chapters in the movie. */
    int * chapters = nullptr; /**< An array of integers representing the chapter details. */
};
#endif