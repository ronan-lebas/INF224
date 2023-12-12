#include "MultimediaObject.h"

class Image : public MultimediaObject {
    private:
        int width {};
        int height {};
    public:
        Image(std::string name, std::string filename, int width, int height);
        ~Image();
        int getWidth() const;

        void setWidth(int newWidth);

        int getHeight() const;

        void setHeight(int newHeight);

        void play() const;
        
};
