#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "Book.hpp"
#include "Genre.hpp"
#include "Shelf.hpp"

#include <string>

bool operator==(Book lhs, Book rhs)
{
    return lhs.get_author() == rhs.get_author() && lhs.get_title() == rhs.get_title() &&
           lhs.get_year() == rhs.get_year() && lhs.get_genre() == rhs.get_genre();
}

TEST_CASE("Book Tests"
          "[book]")
{
    SECTION("Book Creation")
    {
        Book book{ "Stephen King", "It", 1986, Genre::FICTION };
        REQUIRE(true);
    }

    // This book will be used for the getters and print tests
    Book dune{ "Frank Herbert", "Dune", 1965, Genre::SCI_FI };

    SECTION("get_author()") { REQUIRE(dune.get_author() == "Frank Herbert"); }

    SECTION("get_title()") { REQUIRE(dune.get_title() == "Dune"); }

    SECTION("get_year()") { REQUIRE(dune.get_year() == 1965); }

    SECTION("get_genre()") { REQUIRE(dune.get_genre() == Genre::SCI_FI); }

    SECTION("print()")
    {
        std::ostringstream sout;
        dune.print(sout);
        REQUIRE(sout.str() == "Dune by Frank Herbert, published 1965 (Sci-fi)\n");
    }
}

TEST_CASE("Shelf Tests", "[shelf]")
{
    // Books available to the remaining tests
    Book salem("Stephen King", "Salem's Lot", 1975, Genre::FICTION);
    Book it("Stephen King", "It", 1986, Genre::FICTION);
    Book pillars("Ken Follet", "The Pillars of the Earth", 1989, Genre::FICTION);
    Book hobbit("J.R.R. Tolkien", "The Hobbit", 1937, Genre::CHILDRENS);
    Book jumanji("Chriss Van Allsburg", "Jumanji", 1981, Genre::CHILDRENS);
    Book redwall("Brian Jacques", "Redwall", 1986, Genre::FANTASY);
    Book poirot("Agatha Christie", "Curtain", 1975, Genre::MYSTERY);
    Book sevenPercent("Nicholas Meyer", "The Seven-Per-Cent Solution", 1974, Genre::MYSTERY);
    Book hamilton("Ron Chernow", "Alexander Hamilton", 2004, Genre::NON_FICTION);
    Book blade("Phillip K. Dick", "Do Androids Dream of Electric Sheep?", 1968, Genre::SCI_FI);
    Book dune("Frank Herbert", "Dune", 1965, Genre::SCI_FI);

    SECTION("Shelf Creation & size()")
    {
        Shelf shelf;
        REQUIRE(shelf.size() == 0);
    }

    SECTION("add_book() & remove_book()")
    {
        Shelf shelf;

        shelf.add_book(it);
        REQUIRE(shelf.size() == 1);

        shelf.remove_book(0);
        REQUIRE(shelf.size() == 0);
    }

    // Used for genre_count() and sort_by_title()
    Shelf shelf;
    shelf.add_book(salem);
    shelf.add_book(it);
    shelf.add_book(pillars);
    shelf.add_book(hobbit);
    shelf.add_book(jumanji);
    shelf.add_book(redwall);
    shelf.add_book(poirot);
    shelf.add_book(sevenPercent);
    shelf.add_book(hamilton);
    shelf.add_book(blade);
    shelf.add_book(dune);

    SECTION("genre_count()")
    {
        REQUIRE(shelf.genre_count(Genre::SCI_FI) == 2);
        REQUIRE(shelf.genre_count(Genre::FICTION) == 3);
        REQUIRE(shelf.genre_count(Genre::CHILDRENS) == 2);
        REQUIRE(shelf.genre_count(Genre::FANTASY) == 1);
        REQUIRE(shelf.genre_count(Genre::NON_FICTION) == 1);
        REQUIRE(shelf.genre_count(Genre::MYSTERY) == 2);
    }

    SECTION("sort_by_title()")
    {
        shelf.sort_by_title();

        REQUIRE(shelf.get_book(0) == hamilton);
        REQUIRE(shelf.get_book(1) == poirot);
        REQUIRE(shelf.get_book(2) == blade);
        REQUIRE(shelf.get_book(3) == dune);
        REQUIRE(shelf.get_book(4) == it);
        REQUIRE(shelf.get_book(5) == jumanji);
        REQUIRE(shelf.get_book(6) == redwall);
        REQUIRE(shelf.get_book(7) == salem);
        REQUIRE(shelf.get_book(8) == hobbit);
        REQUIRE(shelf.get_book(9) == pillars);
        REQUIRE(shelf.get_book(10) == sevenPercent);
    }

    SECTION("read_books_from_file()", "[file]")
    {
        Shelf shelf;
        read_books_from_file("booklist.txt", shelf);
        REQUIRE(shelf.get_book(0) ==
                Book("Ken Follet", "The Pillars of the Earth", 1989, Genre::FICTION));
        REQUIRE(shelf.get_book(1) == Book("Ken Follet", "World Without End", 2007, Genre::FICTION));
        REQUIRE(shelf.get_book(2) == Book("Ken Follet", "A Column of Fire", 2017, Genre::FICTION));
        REQUIRE(shelf.get_book(3) == Book("Brian Jacques", "Redwall", 1986, Genre::FANTASY));
        REQUIRE(shelf.get_book(4) == Book("Brian Jacques", "Mossflower", 1988, Genre::FANTASY));
        REQUIRE(shelf.get_book(5) == Book("Brian Jacques", "Mattimeo", 1989, Genre::FANTASY));
        REQUIRE(shelf.get_book(6) ==
                Book("Brian Jacques", "Mariel of Redwall", 1991, Genre::FANTASY));
        REQUIRE(shelf.get_book(7) == Book("Brian Jacques", "Salamandastron", 1992, Genre::FANTASY));
        REQUIRE(shelf.get_book(8) ==
                Book("Brian Jacques", "Martin the Warrior", 1993, Genre::FANTASY));
        REQUIRE(shelf.get_book(9) == Book("Sir Arthur Conan Doyle", "The Hound of the Baskervilles",
                                          1902, Genre::MYSTERY));
    }

    SECTION("Functional Test", "[functional]")
    {
        Shelf shelf;
        read_books_from_file("booklist.txt", shelf);
        REQUIRE(shelf.size() == 10);

        shelf.add_book(it);
        shelf.add_book(salem);
        shelf.add_book(hobbit);
        shelf.add_book(jumanji);
        shelf.add_book(poirot);
        shelf.add_book(hamilton);
        shelf.add_book(sevenPercent);
        shelf.add_book(blade);
        REQUIRE(shelf.size() == 18);

        shelf.sort_by_title();

        shelf.remove_book(4);
        REQUIRE(shelf.get_book(4) == jumanji);

        shelf.remove_book(4);
        REQUIRE(shelf.get_book(4) ==
                Book("Brian Jacques", "Mariel of Redwall", 1991, Genre::FANTASY));

        shelf.remove_book(shelf.size() - 1);
        REQUIRE(shelf.size() == 15);
    }
}