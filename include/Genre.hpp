#ifndef GENRE_HPP
#define GENRE_HPP

#include <limits>
#include <string>

enum class Genre : unsigned int {
    CHILDRENS   = 0,
    FANTASY     = 1,
    FICTION     = 2,
    MYSTERY     = 3,
    NON_FICTION = 4,
    SCI_FI      = 5,
    ERR         = std::numeric_limits<unsigned int>::max()
};

// Functions for the enum
std::string genre_to_string(Genre genre);
Genre       string_to_genre(std::string genre);

#endif