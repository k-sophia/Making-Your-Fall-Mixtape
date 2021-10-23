/****************************************************************************************************************************
Title       : AudioBook.hpp
Auhors      : Kelly Camacho
Description : header/interface file of a AudioBook object class which inherits from the abstract PlaylistItem class
****************************************************************************************************************************/

#ifndef AUDIO_BOOK_H_
#define AUDIO_BOOK_H_

#include "PlaylistItem.hpp"

class AudioBook : public PlaylistItem {
    public:
        AudioBook(std::string title, double length, std::string genre, 
                             std::string author, std::string speaker);

        std::string getAuthor() const;
        std::string getSpeaker() const;

        void setAuthor(std::string author);
        void setSpeaker(std::string speaker);

        /*
            Goal: Displays the member variables to the console. 
                Format is based on the given example in audioBookExample.txt.
        */
        void display() const;
        
    private:
        std::string author_;
        std::string speaker_;

};

#endif  //end AUDIO_BOOK_H_

