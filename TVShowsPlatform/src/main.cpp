#include "TvShow.h"
#include <iostream>

int main() {
    // Create two `TvShow` objects
    TvShow series1("The Haunting of Bly Manor", "Horror", 9, "A chilling story of love and ghosts.");
    TvShow series2("The Haunting of Hill House", "Horror", 10, "A family's haunting memories of their old home.");

    // Assign `series1` to `series2` using the overloaded assignment operator
    series2 = series1;

    // Display information for `series2` to verify it was copied correctly
    std::cout << "Series2 Title: " << series2.getTitle() << std::endl;
    std::cout << "Series2 Genre: " << series2.getGenre() << std::endl;
    std::cout << "Series2 Episodes: " << series2.getEpisodes() << std::endl;

    return 0;
}
