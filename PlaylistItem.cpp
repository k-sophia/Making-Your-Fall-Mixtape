/****************************************************************************************************************************
Title        : PlaylistItem.hpp
Auhors       : Kelly Camacho
Description  : partial implementation file of an abstract class
Dependencies : PlaylistItem.hpp
****************************************************************************************************************************/

#include "PlaylistItem.hpp"
#include <string>

/* Constructor */
PlaylistItem::PlaylistItem(std::string title, double length, std::string genre) {
    title_ = title;
    length_ = length;
    genre_ = genre;
}   // end constructor

std::string PlaylistItem::getTitle() const {
    return title_;
}

double PlaylistItem::getLength() const {
    return length_;
}

std::string PlaylistItem::getGenre() const {
    return genre_;
}

void PlaylistItem::setTitle(std::string title) {
    title_ = title;
}

void PlaylistItem::setLength(double length) {
    length_ = length;
}

void PlaylistItem::setGenre(std::string genre) {
    genre_ = genre;
}

