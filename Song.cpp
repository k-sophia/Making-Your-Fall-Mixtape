/****************************************************************************************************************************
Title        : Song.cpp
Auhors       : Kelly Camacho
Description  : implementation file of a Song object class which inherits from the abstract PlaylistItem class
Dependencies : Song.hpp
****************************************************************************************************************************/

#include "Song.hpp"
#include <string>

/* Constructor */
Song::Song(std::string title, double length, std::string genre, std::string artist) : PlaylistItem(title, length, genre) {
    artist_ = artist;
}

std::string Song::getArtist() const {
    return artist_;
}

void Song::setArtist(std::string artist) {
    artist_ = artist;
}

void Song::display() const {
    std::cout << getTitle() << std::endl;
    std::cout << "Artist: " << getArtist() << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Length: " << getLength() << std::endl << std::endl;
}

