#ifndef VIDEO_H
#define VIDEO_H
#include "MultimediaObject.h"

/**
 * @brief The Video class represents a multimedia video object.
 * 
 * This class inherits from the MultimediaObject class and adds a duration attribute.
 * It provides methods to get and set the duration, print the video details, play the video,
 * get the class name, and serialize/deserialize the video object.
 */
class Video : public MultimediaObject {
    private:
        int duration{}; /**< The duration of the video in seconds. */
    public:
        /**
         * @brief Default constructor for the Video class.
         */
        Video();
        
        /**
         * @brief Parameterized constructor for the Video class.
         * 
         * @param name The name of the video.
         * @param filename The filename of the video.
         * @param duration The duration of the video in seconds.
         */
        Video(std::string name, std::string filename, int duration);
        
        /**
         * @brief Destructor for the Video class.
         */
        ~Video();
        
        /**
         * @brief Get the duration of the video.
         * 
         * @return The duration of the video in seconds.
         */
        int getDuration() const;
        
        /**
         * @brief Set the duration of the video.
         * 
         * @param newDuration The new duration of the video in seconds.
         */
        void setDuration(int newDuration);
        
        /**
         * @brief Print the details of the video.
         * 
         * @param out The output stream to print the details to.
         */
        void print(std::ostream& out) const;
        
        /**
         * @brief Play the video.
         */
        void play() const;
        
        /**
         * @brief Get the class name of the video.
         * 
         * @return The class name of the video.
         */
        std::string classname() const override;
        
        /**
         * @brief Serialize the video object.
         * 
         * @param out The output stream to serialize the object to.
         */
        void serialize(std::ostream & out) const override;
        
        /**
         * @brief Deserialize the video object.
         * 
         * @param in The input stream to deserialize the object from.
         */
        void deserialize(std::istream & in) override;
};
#endif