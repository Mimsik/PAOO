#ifndef TVSHOW_H
#define TVSHOW_H

#include <string>

class TvShow {
private:
    std::string title;
    std::string genre;
    int episodes;
    char* description;

public:
    // Constructor
    TvShow(const std::string& title, const std::string& genre, int episodes, const char* desc);
    
    // Copy-Constructor
    TvShow(const TvShow& other);

    // Destructor
    ~TvShow();

    // Assignment operator
    TvShow& operator=(const TvShow& other);

    // Getters and setters
    std::string getTitle() const;
    void setTitle(const std::string& title);

    std::string getGenre() const;
    void setGenre(const std::string& genre);

    int getEpisodes() const;
    void setEpisodes(int episodes);
};

#endif 
