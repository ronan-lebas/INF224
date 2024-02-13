//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <sstream>
#include "MultimediaObject.h"
#include "Image.h"
#include "Video.h"
#include "Movie.h"
#include "Group.h"
#include "Manager.h"
#include "tcpserver.h"
using namespace std;

//#define VERSION_TEST
#ifdef VERSION_TEST
int main(int argc, const char* argv[])
{
    std::cout << "-----Test du manager-----" << std::endl;
    Manager * manager = new Manager();

    ObjectPtr image =  manager->createImage("Image", "image.jpg", 100, 200);
    ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
    ObjectPtr image2 = manager->createImage("Image2", "image2.jpg", 100, 200);
    ObjectPtr video2 = manager->createVideo("Video2", "video2.mp4", 60);
    GroupPtr group = manager->createGroup("Groupe de test");
    group->push_back(image);
    group->push_back(video);

    manager->printObject(std::cout, "Image");
    manager->printObject(std::cout, "Video");
    manager->printObject(std::cout, "Image2");
    manager->printObject(std::cout, "Video2");
    manager->printGroup(std::cout, "Groupe de test");
    manager->play("Image");
    manager->play("Video");
    manager->remove("Image");
    manager->remove("Video");
    group->print(std::cout);

    return 0;
}
#endif

#define VERSION_SERVER
#ifdef VERSION_SERVER

int main(int argc, const char * argv[]){
    
    const int PORT = 3331;
    Manager * manager = new Manager();
    ObjectPtr image = manager->createImage("Image", "image.jpg", 100, 200);
    ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
    GroupPtr group = manager->createGroup("Groupe de test");
    group->push_back(image);
    group->push_back(video);

    // cree le TCPServer
    auto* server = new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        std::string requestType = request.substr(0,request.find("-"));
        std::string name = request.substr(request.find("-")+1);
        std::stringstream ss;

        if (requestType == "searchobject"){
            manager->printObject(ss, name);
        }
        else if (requestType == "searchgroup"){
            manager->printGroup(ss, name);
        }
        else if (requestType == "play"){
            manager->play(name);
        }
        std::cout << requestType << std::endl;
        std::cout << name << std::endl;
        std::cout << ss.str() << std::endl;
        response = ss.str();
        // the response that the server sends back to the client
        //response = "RECEIVED: " + request;

        // return false would close the connecytion with the client
        return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
    }
    
    return 0;
}
#endif

//#define VERSION_SERIAL
#ifdef VERSION_SERIAL

int main() {
    
    std::cout << "-----Test de la sérialisation-----" << std::endl;
    Manager * manager = new Manager();
    ObjectPtr image =  manager->createImage("Image", "image.jpg", 100, 200);
    ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
    ObjectPtr image2 = manager->createImage("Image2", "image2.jpg", 100, 200);
    ObjectPtr video2 = manager->createVideo("Video2", "video2.mp4", 60);
    ObjectPtr movie = manager->createMovie("Movie", "movie.mp4", 120, 3, new int[3]{20, 40, 60});

    manager->printAllObjects(std::cout);


    std::string filename = "test.txt";
    manager->saveObjects(filename);

    std::cout << "-----Test de la désérialisation-----" << std::endl;

    Manager * manager2 = new Manager();
    manager2->readObjects(filename);
    manager2->printAllObjects(std::cout);

    return 0;
}

#endif