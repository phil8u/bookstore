#include <cstdint>

#include <book.h>

#ifndef BOOKSHELF_H
#define BOOKSHELF_H

class Bookshelf {
  private:
    uint8_t levels;
    uint8_t slots;
  public:
    Book **books;
    Bookshelf(uint8_t levels, uint8_t slots);
    ~Bookshelf();
    Book& getBook(const std::string& title);
    void putBook(Book& book);
};

#endif