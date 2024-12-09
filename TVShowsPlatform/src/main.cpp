#include "LimitedSeries.h"
#include <vector>
#include <iostream>

// Function to display a top 3 list
void displayLimitedTop3(const std::vector<std::shared_ptr<LimitedSeries>>& top3) {
    std::cout << "\nTop 3 Limited Series:\n";
    for (size_t i = 0; i < top3.size(); ++i) {
        std::cout << i + 1 << ". " << top3[i]->getTitle() << " (" 
                  << top3[i]->getGenre() << ", " 
                  << top3[i]->getEpisodes() << " episodes, " 
                  << top3[i]->getAvailableDays() << " days left)\n";
    }
    std::cout << std::endl;
}

int main() {
     auto limited1 = std::make_shared<LimitedSeries>("Chernobyl", "Historical", 5, "The true story of a nuclear disaster.", 1, 10);
    auto limited2 = std::make_shared<LimitedSeries>("Band of Brothers", "War", 10, "A story of camaraderie during WWII.", 1, 5);
    auto limited3 = std::make_shared<LimitedSeries>("The Queen's Gambit", "Drama", 7, "A chess prodigy's journey.", 1, 8);

    // Use of shared pointer
    std::vector<std::shared_ptr<LimitedSeries>> top3 = {limited1, limited2, limited3};
    displayLimitedTop3(top3);

    for (auto& series : top3) {
        series->decreaseAvailableDays();
    }

    displayLimitedTop3(top3);
    
    return 0;
}
