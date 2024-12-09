#ifndef TVSHOW_H
#define TVSHOW_H

#include <string>
#include <memory>  // For std::unique_ptr

class TvShow {
private:
    std::string title;
    std::string genre;
    int episodes;
    std::unique_ptr<char[]> description;  // Replacing raw pointer with unique_pointer

public:
    // Constructor
    TvShow(const std::string& title, const std::string& genre, int episodes, const char* desc);

    // Copy Constructor
    TvShow(const TvShow& other);

    // Move Constructor
    TvShow(TvShow&& other) noexcept;

    // Destructor
    ~TvShow() = default;

    // Assignment Operators
    TvShow& operator=(const TvShow& other);
    TvShow& operator=(TvShow&& other) noexcept;

    // Getters and Setters
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getGenre() const;
    void setGenre(const std::string& genre);
    int getEpisodes() const;
    void setEpisodes(int episodes);
};

#endif
