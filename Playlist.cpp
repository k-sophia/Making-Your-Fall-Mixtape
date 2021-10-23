/****************************************************************************************************************************
Title        : Playlist.hpp
Auhors       : Kelly Camacho
Description  : partial implementation file of a child class
Dependencies : Playlist.hpp
****************************************************************************************************************************/

#include "Playlist.hpp"

/* Constructor */ 
Playlist::Playlist() : DoublyLinkedList() 
{

}   //end constructor

double Playlist::getTotalTime() const { 
    double total_time = 0.0;
    for(int i = 1; i <= DoublyLinkedList::getSize(); i++) { 
        total_time += getEntry(i)->getLength();
    }   //end for

    return total_time;
}   //end getTotalTime

void Playlist::operator+=(Playlist rhs) {
    for(int i = 1; i <= rhs.getSize(); i++) {
        DoublyLinkedList::insert(rhs.getEntry(i), DoublyLinkedList::getSize() + 1);
    }   //end for
}   //end operator+=

void Playlist::operator-=(Playlist rhs) {
    for(int i = 1; i <= rhs.getSize(); i++) {
        if(getEntry(i) == rhs.getEntry(i)) {
            DoublyLinkedList::remove(i);
        }   //end if
    }   //end for
}   //end operator-=

void Playlist::skip() {
    DoublyLinkedList::insert(getEntry(DoublyLinkedList::getSize()), 1);
    DoublyLinkedList::remove(DoublyLinkedList::getSize()); 
}   //end skip

void Playlist::rewind() {
    DoublyLinkedList::insert(getEntry(DoublyLinkedList::getSize()), 1);
    DoublyLinkedList::remove(DoublyLinkedList::getSize());
}   //end reqind

void Playlist::display() {
   for(int i = 1; i <= DoublyLinkedList::getSize(); i++) {
       getEntry(i)->display();
    }   //end for

}   //end display