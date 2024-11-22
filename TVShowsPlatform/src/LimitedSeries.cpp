#include "LimitedSeries.h"
#include <iostream>

// Constructor
LimitedSeries::LimitedSeries(const std::string& title, const std::string& genre, int episodes, const char* desc, int seasons, int availableDays)
    : TvShow(title, genre, episodes, desc), seasons(seasons), availableDays(availableDays) {
    std::cout << "LimitedSeries: Object '" << title << "' was created with " << availableDays << " days available.\n";
}

// Copy Constructor
LimitedSeries::LimitedSeries(const LimitedSeries& other)
    : TvShow(other), seasons(other.seasons), availableDays(other.availableDays) {
    std::cout << "LimitedSeries: Copy constructor called for '" << other.getTitle() << "'.\n";
}

// Move Constructor
LimitedSeries::LimitedSeries(LimitedSeries&& other) noexcept
    : TvShow(std::move(other)), seasons(other.seasons), availableDays(other.availableDays) {
    other.seasons = 0;
    other.availableDays = 0;
    std::cout << "LimitedSeries: Move constructor called for '" << getTitle() << "'.\n";
}

// Copy Assignment Operator
LimitedSeries& LimitedSeries::operator=(const LimitedSeries& other) {
    if (this != &other) {
        TvShow::operator=(other);  // Assign base part
        seasons = other.seasons;
        availableDays = other.availableDays;
    }
    std::cout << "LimitedSeries: Copy assignment operator called for '" << getTitle() << "'.\n";
    return *this;
}

// Move Assignment Operator
LimitedSeries& LimitedSeries::operator=(LimitedSeries&& other) noexcept {
    if (this != &other) {
        TvShow::operator=(std::move(other));  // Move base part
        seasons = other.seasons;
        availableDays = other.availableDays;

        other.seasons = 0;
        other.availableDays = 0;
    }
    std::cout << "LimitedSeries: Move assignment operator called for '" << getTitle() << "'.\n";
    return *this;
}

// Destructor
LimitedSeries::~LimitedSeries() {
    std::cout << "LimitedSeries: Object '" << getTitle() << "' was destroyed.\n";
}

// Getter for available days
int LimitedSeries::getAvailableDays() const {
    return availableDays;
}

// Decrease available days
void LimitedSeries::decreaseAvailableDays() {
    if (availableDays > 0) {
        --availableDays;
        std::cout << "LimitedSeries: '" << getTitle() << "' has " << availableDays << " days left.\n";
    }
    if (availableDays == 0) {
        std::cout << "LimitedSeries: '" << getTitle() << "' is no longer available!\n";
    }
}
