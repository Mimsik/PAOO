#ifndef LIMITEDSERIES_H
#define LIMITEDSERIES_H

#include "TvShow.h"

class LimitedSeries : public TvShow {
private:
    int seasons;

public:
    // Constructor
    LimitedSeries(const std::string& title, const std::string& genre, int episodes, const char* desc, int seasons);

    // Copy Constructor
    LimitedSeries(const LimitedSeries& other);

    // Move Constructor
    LimitedSeries(LimitedSeries&& other) noexcept;

    // Destructor
    ~LimitedSeries();
};

#endif
