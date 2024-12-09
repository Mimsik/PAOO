#ifndef LIMITEDSERIES_H
#define LIMITEDSERIES_H

#include "TvShow.h"
#include <mutex>  // Pentru std::mutex

class LimitedSeries : public TvShow {
private:
    int seasons;
    int availableDays;
    mutable std::mutex daysMutex;  // Mutex for synchronization

public:
    // Constructor
    LimitedSeries(const std::string& title, const std::string& genre, int episodes, const char* desc, int seasons, int availableDays);

    // Copy Constructor
    LimitedSeries(const LimitedSeries& other);

    // Move Constructor
    LimitedSeries(LimitedSeries&& other) noexcept;

    // Assignment Operators
    LimitedSeries& operator=(const LimitedSeries& other);
    LimitedSeries& operator=(LimitedSeries&& other) noexcept;

    // Destructor
    ~LimitedSeries();

    // Getter and days management
    int getAvailableDays() const;
    void decreaseAvailableDays();
};

#endif
