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

/**
 * @class Manager
 * @brief The Manager class represents a manager for objects and groups.
 * 
 * The Manager class provides functionality to create, manage, and manipulate objects and groups.
 * It maintains a collection of objects and groups using std::map data structures.
 * Objects can be created and added to the manager, and groups can be created and managed by adding objects to them.
 * The manager also provides methods to print objects and groups, play objects, remove objects, and save/read objects from a file.
 */
class Manager {
    private:
        std::map<std::string, ObjectPtr> objects; /**< A map of objects, where the key is the object name and the value is a shared pointer to the object. */
        std::map<std::string, GroupPtr> groups; /**< A map of groups, where the key is the group name and the value is a shared pointer to the group. */

    public:
        /**
         * @brief Default constructor for the Manager class.
         */
        Manager();

        /**
         * @brief Destructor for the Manager class.
         */
        ~Manager();

        /**
         * @brief Creates an image object and adds it to the manager.
         * @param name The name of the image.
         * @param filename The filename of the image.
         * @param width The width of the image.
         * @param height The height of the image.
         * @return A shared pointer to the created image object.
         */
        ObjectPtr createImage(const std::string name, const std::string filename, const int width, const int height);

        /**
         * @brief Creates a video object and adds it to the manager.
         * @param name The name of the video.
         * @param filename The filename of the video.
         * @param duration The duration of the video.
         * @return A shared pointer to the created video object.
         */
        ObjectPtr createVideo(const std::string name, const std::string filename, const int duration);

        /**
         * @brief Creates a movie object and adds it to the manager.
         * @param name The name of the movie.
         * @param filename The filename of the movie.
         * @param duration The duration of the movie.
         * @param chaptersNumber The number of chapters in the movie.
         * @param chapters An array of chapter durations.
         * @return A shared pointer to the created movie object.
         */
        ObjectPtr createMovie(const std::string name, const std::string filename, const int duration, const int chaptersNumber, const int * chapters);

        /**
         * @brief Creates a group object and adds it to the manager.
         * @param name The name of the group.
         * @return A shared pointer to the created group object.
         */
        GroupPtr createGroup(const std::string name);

        /**
         * @brief Prints the details of an object to the specified output stream.
         * @param out The output stream to print to.
         * @param name The name of the object to print.
         */
        void printObject(std::ostream & out, const std::string name) const;

        /**
         * @brief Prints the details of all objects to the specified output stream.
         * @param out The output stream to print to.
         */
        void printAllObjects(std::ostream & out) const;

        /**
         * @brief Prints the details of a group to the specified output stream.
         * @param out The output stream to print to.
         * @param name The name of the group to print.
         */
        void printGroup(std::ostream & out, const std::string name) const;

        /**
         * @brief Plays the specified object.
         * @param name The name of the object to play.
         */
        void play(const std::string name) const;

        /**
         * @brief Removes the specified object from the manager.
         * @param name The name of the object to remove.
         */
        void remove(const std::string name);

        /**
         * @brief Saves the objects in the manager to a file.
         * @param filename The name of the file to save to.
         * @return True if the objects were successfully saved, false otherwise.
         */
        bool saveObjects(std::string filename) const;

        /**
         * @brief Reads objects from a file and adds them to the manager.
         * @param filename The name of the file to read from.
         * @return True if the objects were successfully read and added, false otherwise.
         */
        bool readObjects(std::string filename);

        /**
         * @brief Creates an object of the specified class name.
         * @param classname The name of the class to create an object of.
         * @return A shared pointer to the created object, or nullptr if the class name is invalid.
         */
        ObjectPtr createObject(std::string classname) const;

        /**
         * @brief Checks if a given name is already used by an object or group in the manager.
         * @param name The name to check.
         * @return True if the name is already used, false otherwise.
         */
        bool checkNames(std::string name) const;
};

#endif