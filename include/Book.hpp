#ifndef BOOK_HPP
#define BOOK_HPP

#include "Genre.hpp"

#include <iostream>
#include <string>

class Book {
public:
    Book(std::string auth, std::string title, int year, Genre genre);
    std::string get_author();
    std::string get_title();
    int         get_year();
    Genre       get_genre();
    void        print(std::ostream& sout = std::cout);

private:
    std::string m_author;
    std::string m_title;
    int         m_year = 0;
    Genre       m_genre;
};

#endif