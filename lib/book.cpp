#include <string>

#include <book.h>

Book::Book() {
    title = "";
    author = "";
    pages = nullptr;
    numPages = 0;
}
// Constructor
Book::Book(const std::string& t, const std::string& a, int n)
    : title(t), author(a), numPages(n) {
    pages = new int[numPages];
    for (int i = 1; i <= numPages; i++)  {
        pages[i] = i;
    }
}

// Destructor
Book::~Book() {
    delete[] pages;
}

// Copy Constructor
Book::Book(const Book& other)
    : title(other.title), author(other.author), numPages(other.numPages) {
    pages = new int[numPages];
    std::copy(other.pages, other.pages + numPages, pages);
}

// Copy Assignment Operator
Book& Book::operator=(const Book& other) {
    if (this == &other) return *this;
    // Clean up existing resources
    delete[] pages;
    // Copy data from the other object
    title = other.title;
    author = other.author;
    numPages = other.numPages;
    pages = new int[numPages];
    std::copy(other.pages, other.pages + numPages, pages);
    return *this;
}

// Move Constructor
Book::Book(Book&& other) noexcept
    : title(std::move(other.title)), author(std::move(other.author)),
      pages(other.pages), numPages(other.numPages) {
    other.pages = nullptr;
    other.numPages = 0;
}

// Move Assignment Operator
Book& Book::operator=(Book&& other) noexcept {
    if (this == &other) return *this;

    delete[] pages;
    // Move data from the other object
    title = std::move(other.title);
    author = std::move(other.author);
    pages = other.pages;
    numPages = other.numPages;

    // Nullify the other pointer
    other.pages = nullptr;
    other.numPages = 0;

    return *this;
}
bool Book::isEmpty() {
  return title == "";
}

