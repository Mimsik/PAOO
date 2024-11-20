#include "LimitedSeries.h"
#include <iostream>

// Constructor
LimitedSeries::LimitedSeries(const std::string& title, const std::string& genre, int episodes, const char* desc, int seasons)
    : TvShow(title, genre, episodes, desc), seasons(seasons) {

    std::cout << "LimitedSeries: Object '" << title << "' was created." << std::endl;
}

// Copy Constructor
LimitedSeries::LimitedSeries(const LimitedSeries& other)
    : TvShow(other), seasons(other.seasons) {

    std::cout << "LimitedSeries: Copy constructor called for '" << other.getTitle() << "'." << std::endl;
}

// Move Constructor
LimitedSeries::LimitedSeries(LimitedSeries&& other) noexcept
    : TvShow(std::move(other)), seasons(other.seasons) {
    other.seasons = 0; // Reset source object state
    
    std::cout << "LimitedSeries: Move constructor called for '" << getTitle() << "'." << std::endl;
}

// Destructor
LimitedSeries::~LimitedSeries() {
    std::cout << "LimitedSeries: Object '" << getTitle() << "' was destroyed." << std::endl;
}
