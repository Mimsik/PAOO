#include "LimitedSeries.h"
#include <vector>
#include <iostream>

// Function to display a top 3 list
void displayLimitedTop3(const std::vector<LimitedSeries>& top3) {
    std::cout << "\nTop 3 Limited Series:\n";
    for (size_t i = 0; i < top3.size(); ++i) {
        std::cout << i + 1 << ". " << top3[i].getTitle() << " (" << top3[i].getGenre()
                  << ", " << top3[i].getEpisodes() << " episodes, " << top3[i].getAvailableDays() << " days left)\n";
    }
    std::cout << std::endl;
}

int main() {
    // Create LimitedSeries objects
    LimitedSeries limited1("Chernobyl", "Historical", 5, "The true story of a nuclear disaster.", 1, 10);
    LimitedSeries limited2("Band of Brothers", "War", 10, "A story of camaraderie during WWII.", 1, 5);
    LimitedSeries limited3("The Queen's Gambit", "Drama", 7, "A chess prodigy's journey.", 1, 8);
    TvShow series1 = LimitedSeries(limited1);

    // Initial top 3 list
    std::vector<LimitedSeries> top3;
    top3.reserve(3);
    top3.push_back(limited1);  // Copy constructor
    top3.push_back(limited2);  // Copy constructor
    top3.push_back(limited3);  // Copy constructor
    displayLimitedTop3(top3);

    // Decrease available days for each series
    for (auto& series : top3) {
        series.decreaseAvailableDays();
    }

    // Move expired series to another vector
    std::vector<LimitedSeries> expired;
    for (auto it = top3.begin(); it != top3.end();) {
        //std::cout << "Checking series: " << it->getTitle() << " - Days left: " << it->getAvailableDays() << "\n";
        if (it->getAvailableDays() == 0) {
            std::cout << "Series '" << it->getTitle() << "' has expired. Moving to expired vector.\n";
            expired.push_back(std::move(*it));  // Move constructor
            it = top3.erase(it);  // Remove from top3
        } else {
            ++it;
        }
    }

    // Display updated top 3 list
    std::cout << "\nAfter expiration check:";
    displayLimitedTop3(top3);

    // Display expired series
    std::cout << "\nExpired Limited Series:\n";
    if (expired.size() != 0) {
        for (const auto& series : expired) {
            std::cout << "- " << series.getTitle() << "\n";
        }
        std::cout << "\n";
    }
    else std::cout << "\nCurrently empty - no expired series for now\n";

    return 0;
}
