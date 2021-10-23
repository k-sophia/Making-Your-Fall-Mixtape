/****************************************************************************************************************************
Title       : Podcast.hpp
Auhors      : Kelly Camacho
Description : header/interface file of a Podcast object class which inherits from the abstract PlaylistItem class
****************************************************************************************************************************/

#ifndef PODCAST_H_
#define PODCAST_H_

#include "PlaylistItem.hpp"

class Podcast : public PlaylistItem {
    public:
        Podcast(std::string title, double length, std::string genre, 
                std::string nameOfPodcast, std::string host, std::string guest);

        std::string getNameOfPodcast() const;
        std::string getHost() const;
        std::string getGuest() const;

        void setNameOfPodcast(std::string nameOfPodcast);
        void setHost(std::string host);
        void setGuest(std::string guest);

        /*
            Goal: Displays the member variables to the console. 
                    Format is based on the given example in podcastExample.txt.
        */
        void display() const;

    private:
        std::string name_of_podcast_;
        std::string host_;
        std::string guest_;
};

#endif  //end PODCAST_H_

