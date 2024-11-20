#include "TvShow.h"
#include <cstring>
#include <iostream>

// Constructor
TvShow::TvShow(const std::string& title, const std::string& genre, int episodes, const char* desc)
        : title(title), genre(genre), episodes(episodes) {  // Initialization list

        // Allocates memory for 'description'
        description = new char[strlen(desc) + 1];

        // Copies the content of the `desc` variable into the memory pointed to by `description` pointer
        strcpy(description, desc);

        std::cout << "TvShow: Object '" << title << "' was created." << std::endl;
    }

// Copy-Constructor
TvShow::TvShow(const TvShow& other)
        : title(other.title), genre(other.genre), episodes(other.episodes) {

        // Allocates memory for the copy
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);

        std::cout << "TvShow: Copy constructor called for '" << other.title << "'." << std::endl;
    }

// Destructor 
TvShow::~TvShow() {
    // Free the memory
    delete[] description;

    std::cout << "TvShow: Object '" << title << "' was destroyed." << std::endl;
}

// Assignment operator
TvShow& TvShow::operator=(const TvShow& other) {
    if (this != &other) {
        title = other.title;
        genre = other.genre;
        episodes = other.episodes;

        // Free the old memory
        delete[] description;

        // Allocates memory
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
     std::cout << "TvShow: Assignment operator used for '" << other.title << "'." << std::endl;
    return *this;
}

std::string TvShow::getTitle() const { return title; }

void TvShow::setTitle(const std::string& title) { this->title = title; }

std::string TvShow::getGenre() const { return genre; }

void TvShow::setGenre(const std::string& genre) { this->genre = genre; }

int TvShow::getEpisodes() const { return episodes; }

void TvShow::setEpisodes(int episodes) { this->episodes = episodes; }
