/****************************************************************************************************************************
Title        : Podcast.cpp
Auhors       : Kelly Camacho
Description  : implementation file of a Podcast object class which inherits from the abstract PlaylistItem class
Dependencies : Podcast.hpp
****************************************************************************************************************************/

#include "Podcast.hpp"
#include <string>

/* Constructor */
Podcast::Podcast(std::string title, double length, std::string genre, 
            std::string nameOfPodcast, std::string host, std::string guest)
            : PlaylistItem(title, length, genre) {

    name_of_podcast_ = nameOfPodcast;
    host_ = host;
    guest_ = guest;
}   //end constructor 

std::string Podcast::getNameOfPodcast() const {
    return name_of_podcast_;
}

std::string Podcast::getHost() const {
    return host_;
}

std::string Podcast::getGuest() const {
    return guest_;
}

void Podcast::setNameOfPodcast(std::string nameOfPodcast) {
    name_of_podcast_ = nameOfPodcast;
}

void Podcast::setHost(std::string host) {
    host_ = host;
}

void Podcast::setGuest(std::string guest) {
    guest_ = guest;
}

void Podcast::display() const {
    std::cout << getTitle() << std::endl;
    std::cout << "Podcast: " << getNameOfPodcast() << std::endl;
    std::cout << "Host: " << getHost() << std::endl;
    std::cout << "Guest: " << getGuest() << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Length: " << getLength() << std::endl << std::endl;
}


