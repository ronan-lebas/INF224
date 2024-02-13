#ifndef VIDEO_H
#define VIDEO_H
#include "MultimediaObject.h"

class Video : public MultimediaObject {
    private:
        int duration{};
    public:
        Video();
        Video(std::string name, std::string filename, int duration);
        ~Video();
        int getDuration() const;
        void setDuration(int newDuration);
        void print(std::ostream& out) const;
        void play() const;
        std::string classname() const override;
        void serialize(std::ostream & out) const override;
        void deserialize(std::istream & in) override;
};
#endif