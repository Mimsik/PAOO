#include "TvShow.h"
#include <iostream>
#include <cstring>
#include <utility>  // Pentru std::move

TvShow::TvShow(const std::string& title, const std::string& genre, int episodes, const char* desc)
    : title(title), genre(genre), episodes(episodes), description(std::make_unique<char[]>(strlen(desc) + 1)) {
    strcpy(description.get(), desc);
    std::cout << "TvShow: Object '" << title << "' was created." << std::endl;
}

TvShow::TvShow(const TvShow& other)
    : title(other.title), genre(other.genre), episodes(other.episodes),
      description(std::make_unique<char[]>(strlen(other.description.get()) + 1)) {
    strcpy(description.get(), other.description.get());
    std::cout << "TvShow: Copy constructor called for '" << other.title << "'." << std::endl;
}

TvShow::TvShow(TvShow&& other) noexcept
    : title(std::move(other.title)), genre(std::move(other.genre)), episodes(other.episodes),
      description(std::move(other.description)) {
    std::cout << "TvShow: Move constructor called for '" << title << "'." << std::endl;
}

TvShow& TvShow::operator=(const TvShow& other) {
    if (this != &other) {
        title = other.title;
        genre = other.genre;
        episodes = other.episodes;
        description = std::make_unique<char[]>(strlen(other.description.get()) + 1);
        strcpy(description.get(), other.description.get());
    }
    std::cout << "TvShow: Assignment operator used for '" << other.title << "'." << std::endl;
    return *this;
}

TvShow& TvShow::operator=(TvShow&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
        genre = std::move(other.genre);
        episodes = other.episodes;
        description = std::move(other.description);
    }
    std::cout << "TvShow: Move assignment operator used for '" << title << "'." << std::endl;
    return *this;
}

std::string TvShow::getTitle() const { return title; }
void TvShow::setTitle(const std::string& title) { this->title = title; }
std::string TvShow::getGenre() const { return genre; }
void TvShow::setGenre(const std::string& genre) { this->genre = genre; }
int TvShow::getEpisodes() const { return episodes; }
void TvShow::setEpisodes(int episodes) { this->episodes = episodes; }
