/****************************************************************************************************************************
Title        : AudioBook.cpp
Auhors       : Kelly Camacho
Description  : implementation file of a AudioBook object class which inherits from the abstract PlaylistItem class
Dependencies : AudioBook.hpp
****************************************************************************************************************************/

#include "AudioBook.hpp"
#include <string>

/* Constructor */
AudioBook::AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker) : PlaylistItem(title, length, genre) {
    author_ = author;
    speaker_ = speaker;
}   //end constructor

std::string AudioBook::getAuthor() const {
    return author_;
}

std::string AudioBook::getSpeaker() const {
    return speaker_;
}

void AudioBook::setAuthor(std::string author) {
    author_ = author;
}

void AudioBook::setSpeaker(std::string speaker) {
    speaker_ = speaker;
}

void AudioBook::display() const {
    std::cout << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Narrator: " << getSpeaker() << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Length: " << getLength() << std::endl << std::endl;
}


