#ifndef IMAGE_H
#define IMAGE_H

#include "MultimediaObject.h"

class Image : public MultimediaObject {
    private:
        int width {};
        int height {};
    public:
        Image();
        Image(std::string name, std::string filename, int width, int height);
        ~Image();
        int getWidth() const;

        void setWidth(int newWidth);

        int getHeight() const;

        void setHeight(int newHeight);

        void play() const;

        std::string classname() const override;

        void serialize(std::ostream & out) const override;

        void deserialize(std::istream & in) override;
        
};
#endif