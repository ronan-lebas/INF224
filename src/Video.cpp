#include "Video.h"

Video::Video(std::string name, std::string filename, int duration) : MultimediaObject(name, filename), duration(duration) {}

Video::~Video() {}

int Video::getDuration() const {
    return duration;
}

void Video::setDuration(int newDuration) {
    duration = newDuration;
}

void Video::print(std::ostream& out) const {
    out << "Name: " << name << ", ";
    out << "Filename: " << filename << ", ";
    out << "Duration: " << duration << " seconds";
}

void Video::play() const {
    std::string command = "mpv " + filename + " &";
    system(command.c_str());
}
