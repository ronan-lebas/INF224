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

int test()
{
    std::cout << std::endl << std::endl;
    std::cout << "-----Test du manager-----" << std::endl;
    Manager* manager = new Manager();

    int array[3] = {20, 40, 60};
    GroupPtr group;
    try{
        ObjectPtr image =  manager->createImage("Image", "image.jpg", 100, 200);
        ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
        ObjectPtr image2 = manager->createImage("Image2", "image2.jpg", 100, 200);
        ObjectPtr video2 = manager->createVideo("Video2", "video2.mp4", 60);
        ObjectPtr movie = manager->createMovie("Movie", "movie.mp4", 120, 3, array);
        group = manager->createGroup("Groupe de test");
        group->push_back(image);
        group->push_back(video);
        group->push_back(image2);
        group->push_back(video2);
        group->push_back(movie);
    } catch(std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    manager->printObject(std::cout, "Image");
    std::cout << std::endl;
    manager->printObject(std::cout, "Video");
    std::cout << std::endl;
    manager->printObject(std::cout, "Image2");
    std::cout << std::endl;
    manager->printObject(std::cout, "Video2");
    std::cout << std::endl;
    manager->printObject(std::cout, "Movie");
    std::cout << std::endl;
    manager->printGroup(std::cout, "Groupe de test");
    //manager->play("Image");
    //manager->play("Video");
    std::cout << std::endl;
    manager->remove("Image");
    manager->remove("Video");
    manager->remove("Movie");
    std::cout << std::endl;
    group->print(std::cout);
    std::cout << std::endl;

    delete manager;

    return 0;
}

int server(){
    
    std::cout << std::endl << std::endl;
    std::cout << "-----Test du serveur-----" << std::endl;

    const int PORT = 3331;
    Manager * manager = new Manager();
    try {
        ObjectPtr image = manager->createImage("Image", "image.jpg", 100, 200);
        ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
        GroupPtr group = manager->createGroup("Groupe de test");
        group->push_back(image);
        group->push_back(video);
    }
    catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
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
    delete server;
    delete manager;
    return 0;
}

int serial() {
    
    std::cout << std::endl << std::endl;
    std::cout << "-----Test de la sérialisation-----" << std::endl;
    Manager * manager = new Manager();
    int array[3] = {20, 40, 60};
    try {
        ObjectPtr image =  manager->createImage("Image", "image.jpg", 100, 200);
        ObjectPtr video = manager->createVideo("Video", "video.mp4", 60);
        ObjectPtr image2 = manager->createImage("Image2", "image2.jpg", 100, 200);
        ObjectPtr video2 = manager->createVideo("Video2", "video2.mp4", 60);
        ObjectPtr movie = manager->createMovie("Movie", "movie.mp4", 120, 3, array);
    } catch(std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    manager->printAllObjects(std::cout);


    std::string filename = "test.txt";
    manager->saveObjects(filename);

    std::cout << "-----Test de la désérialisation-----" << std::endl;

    Manager * manager2 = new Manager();
    manager2->readObjects(filename);
    manager2->printAllObjects(std::cout);

    delete manager;
    delete manager2;

    return 0;
}

int main(int argc, const char ** argv) {
    std::cout << std::endl << std::endl;
    std::cout << "Les trois fonctions principales vont êtres testées, d'abord la gestion des objets/mémoire, puis la sérialisation, puis le serveur sera lancé" << std::endl;
    test();
    serial();
    server();
    
    return 0;
}