#include "Video.h"

Video::Video(std::string name, std::string filename, int duration) {
    MultimediaObject::setName(name);
    MultimediaObject::setFilename(filename);
    this->duration = duration;
}

Video::~Video() {}

int Video::getDuration() const {
    return duration;
}

void Video::setDuration(int newDuration) {
    duration = newDuration;
}

void Video::print(std::ostream& out) const {
    out << "Name: " << name << std::endl;
    out << "Filename: " << filename << std::endl;
    out << "Duration: " << duration << " seconds" << std::endl;
}

void Video::play() const {
    std::string command = "mpv " + filename + " &";
    system(command.c_str());
}
