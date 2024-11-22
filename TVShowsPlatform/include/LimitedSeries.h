#ifndef LIMITEDSERIES_H
#define LIMITEDSERIES_H

#include "TvShow.h"

class LimitedSeries : public TvShow {
private:
    int seasons;
    int availableDays;  // Number of days available

public:
    // Constructor
    LimitedSeries(const std::string& title, const std::string& genre, int episodes, const char* desc, int seasons, int availableDays);

    // Copy Constructor
    LimitedSeries(const LimitedSeries& other);

    // Move Constructor
    LimitedSeries(LimitedSeries&& other) noexcept;

    // Copy Assignment Operator
    LimitedSeries& operator=(const LimitedSeries& other);

    // Move Assignment Operator
    LimitedSeries& operator=(LimitedSeries&& other) noexcept;

    // Destructor
    ~LimitedSeries();

    // Getter and days management
    int getAvailableDays() const;
    void decreaseAvailableDays();  // Decreases days by 1
};

#endif
