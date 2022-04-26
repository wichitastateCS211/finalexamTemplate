#ifndef SHELF_HPP
#define SHELF_HPP

#include "Book.hpp"
#include "Genre.hpp"

#include <vector>

class Shelf {
public:
    Shelf() = default;
    Book        get_book(std::size_t idx);
    void        add_book(Book book);
    void        remove_book(int idx);
    int         genre_count(Genre genre);
    std::size_t size();
    void        sort_by_title();

private:
    std::vector<Book> m_shelf;
};

void read_books_from_file(std::string filename, Shelf& shelf);

#endif