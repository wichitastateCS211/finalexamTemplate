#include "Genre.hpp"

std::string genre_to_string(Genre genre)
{
    switch (genre) {
    case Genre::CHILDRENS:
        return "Children's";
    case Genre::FANTASY:
        return "Fantasy";
    case Genre::FICTION:
        return "Fiction";
    case Genre::MYSTERY:
        return "Mystery";
    case Genre::NON_FICTION:
        return "Non-fiction";
    case Genre::SCI_FI:
        return "Sci-fi";
    default:
        return "GENRE-ERROR";
    }
}

Genre string_to_genre(std::string genre)
{
    for (auto& c : genre) {
        c = std::toupper(c);
    }

    if (genre == "CHILDRENS") {
        return Genre::CHILDRENS;
    } else if (genre == "FANTASY") {
        return Genre::FANTASY;
    } else if (genre == "FICTION") {
        return Genre::FICTION;
    } else if (genre == "MYSTERY") {
        return Genre::MYSTERY;
    } else if (genre == "NON_FICTION") {
        return Genre::NON_FICTION;
    } else if (genre == "SCI_FI") {
        return Genre::SCI_FI;
    } else {
        return Genre::ERR;
    }
}