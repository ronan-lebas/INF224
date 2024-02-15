#ifndef IMAGE_H
#define IMAGE_H

#include "MultimediaObject.h"

/**
 * @class Image
 * @brief Represents an image object derived from MultimediaObject.
 * 
 * The Image class represents an image object with properties such as width and height.
 * It inherits from the MultimediaObject class and provides methods to manipulate and play the image.
 */

class Image : public MultimediaObject {
    private:
        int width {}; /**< The width of the image. */
        int height {}; /**< The height of the image. */
    public:
        /**
         * @brief Default constructor for the Image class.
         */
        Image();
        
        /**
         * @brief Parameterized constructor for the Image class.
         * @param name The name of the image.
         * @param filename The filename of the image.
         * @param width The width of the image.
         * @param height The height of the image.
         */
        Image(std::string name, std::string filename, int width, int height);
        
        /**
         * @brief Destructor for the Image class.
         */
        ~Image();
        
        /**
         * @brief Get the width of the image.
         * @return The width of the image.
         */
        int getWidth() const;
        
        /**
         * @brief Set the width of the image.
         * @param newWidth The new width of the image.
         */
        void setWidth(int newWidth);
        
        /**
         * @brief Get the height of the image.
         * @return The height of the image.
         */
        int getHeight() const;
        
        /**
         * @brief Set the height of the image.
         * @param newHeight The new height of the image.
         */
        void setHeight(int newHeight);
        
        /**
         * @brief Play the image.
         */
        void play() const;
        
        /**
         * @brief Get the classname of the image.
         * @return The classname of the image.
         */
        std::string classname() const override;
        
        /**
         * @brief Serialize the image to an output stream.
         * @param out The output stream to serialize to.
         */
        void serialize(std::ostream & out) const override;
        
        /**
         * @brief Deserialize the image from an input stream.
         * @param in The input stream to deserialize from.
         */
        void deserialize(std::istream & in) override;
};
#endif