#include <cstdint>
#include <iostream>

#include <book.h>
#include <bookshelf.h>

Bookshelf::Bookshelf(uint8_t levels, uint8_t slots) : levels(levels), slots(slots) {
  // A shelf has multiple levels
  books = new Book*[levels];
  // each level/compartment has a fixed number of slots (slots)
  for (int level=0; level<levels; level++) {
    books[level] = new Book[slots];
  }
}
Bookshelf::~Bookshelf()  {
  delete[] books;
  books = nullptr;
}

void Bookshelf::putBook(Book& book) {
  for (int level=0; level<levels; level++) {
    for (int slot=0; slot<slots; slot++) {
      if (books[level][slot].isEmpty()) {
        books[level][slot] = std::move(book);
        return;
      }
    }
  }
  throw "No free spots in the shelf.";
}

Book& Bookshelf::getBook(const std::string& title) {
  for (int level=0; level<levels; level++) {
    for (int slot=0; slot<slots; slot++) {
      if (books[level][slot].title == title) {
        return books[level][slot];
      }
    }
  }
  throw "Requested Book was not in the shelf.";
}
