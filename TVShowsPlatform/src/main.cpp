#include "TvShow.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Funcție pentru afișarea unui top 3
void displayTop3(const std::vector<TvShow>& top3) {
    std::cout << "Top 3 TV Shows:" << std::endl;
    for (size_t i = 0; i < top3.size(); ++i) {
        std::cout << i + 1 << ". " << top3[i].getTitle() << " (" << top3[i].getGenre() 
                  << ", " << top3[i].getEpisodes() << " episodes)" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Create 5 TvShow objects
    TvShow series1("The Haunting of Bly Manor", "Horror", 9, "A chilling story of love and ghosts.");
    TvShow series2("The Haunting of Hill House", "Horror", 10, "A family's haunting memories of their old home.");
    TvShow series3("Stranger Things", "Sci-Fi", 34, "A group of kids face supernatural forces.");
    TvShow series4("Arcane", "Animation", 9, "The origins of iconic League of Legends champions.");
    TvShow series5("Outer Banks", "Adventure", 30, "A group of teens uncover a long-buried treasure.");
    TvShow series6("Orange is the New Black", "Drama", 91, "The story of women navigating life in prison.");

    // Create a top 3 using the copy constructor
    std::vector<TvShow> top3;
    top3.push_back(series1);  // Copy constructor is called
    top3.push_back(series3);  // Copy constructor is called
    top3.push_back(series5);  // Copy constructor is called

    // Display the top 3 TV Shows
    displayTop3(top3);

    // Replace the top 3 using move constructor
    std::vector<TvShow> newTop3;
    newTop3.push_back(std::move(series4));  // Move constructor is called
    newTop3.push_back(std::move(series2));  // Move constructor is called
    newTop3.push_back(std::move(series3));  // Move constructor is called

    // Display the new top 3 TV Shows
    displayTop3(newTop3);

    return 0;
}
