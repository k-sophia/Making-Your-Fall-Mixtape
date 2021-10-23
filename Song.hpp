/****************************************************************************************************************************
Title       : Song.hpp
Auhors      : Kelly Camacho
Description : header/interface file of a Song object class which inherits from the abstract PlaylistItem class
****************************************************************************************************************************/

#ifndef SONG_H_
#define SONG_H_ 

#include "PlaylistItem.hpp"

class Song : public PlaylistItem {
    public:
        /*
            Parameterized Construtor
            Parameters: title, length, genre, artist
            Goal: Update member variables with given parameters
        */
        Song(std::string title, double length, std::string genre, 
                                            std::string artist);

        /************************ Getter Functions ************************/

        /*
            Goal: Return the value of artist_
        */
        std::string getArtist() const;

        /************************ Setter Functions ************************/

        /*
            Goal: Update the value of artist_ with the given parameter
        */
        void setArtist(std::string artist);

        /************************ Other Functions ************************/

        /*
            Goal: Displays the member variables to the console. 
                Format is based on the given example in songExample.txt.
        */
        void display() const;

    private:
        std::string artist_;
};

#endif  //end SONG_H_