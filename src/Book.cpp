/*
 * Name: 
 * WSUID: 
 * Final Exam
 * Implement Book and Shelf classes
 */

#include "Book.hpp"
#include <string>

    Book::Book(std::string auth, std::string title, int year, Genre genre) : m_author{}, m_title{}, m_year{}, m_genre(Genre::ERR) {}

    std::string Book::get_author()
    {
        return {};
    }

    std::string Book::get_title()
    {
        return {};
    }

    int         Book::get_year()
    {
        return {};
    }

    Genre       Book::get_genre()
    {
        return Genre::ERR;
    }

    void        Book::print(std::ostream& sout)
    {
        return;
    }
