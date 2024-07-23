#include <string>

#ifndef BOOK_H
#define BOOK_H

class Book {
  private:
    int* pages;
    int numPages;

  public:
    std::string title;
    std::string author;
    // Constructors
    Book();
    Book(const std::string& t, const std::string& a, int n);
    // Destructor
    ~Book();
    // Copy Constructor
    Book(const Book& other);
    // Copy Assignment Operator
    Book& operator=(const Book& other);
    // Move Constructor
    Book(Book&& other) noexcept;
    // Move Assignment Operator
    Book& operator=(Book&& other) noexcept;
    bool isEmpty();
};

#endif