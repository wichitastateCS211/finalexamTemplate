/*
 * Name: 
 * WSUID: 
 * Final Exam
 * Implement Book and Shelf classes
 */
 
 #include "Book.hpp"
 #include "Shelf.hpp"

Book        Shelf::get_book(std::size_t idx)
{
    return Book({}, {}, 0, Genre::ERR);
}

void        Shelf::add_book(Book book)
{
    return;
}

void        Shelf::remove_book(int idx)
{
    return;
}

int         Shelf::genre_count(Genre genre)
{
    return 0;
}

std::size_t Shelf::size()
{
    return 0;
}

void        Shelf::sort_by_title()
{
    return;
}

void read_books_from_file(std::string filename, Shelf& shelf)
{
    return;
}