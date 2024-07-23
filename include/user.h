#include <string>
#include <map>

#include <book.h>
#include <bookshelf.h>


#ifndef USER_H
#define USER_H


enum Spot {
  Left = 0,
  Middle = 1,
  Right = 2
};

class User {
  public:
    User();
    User(std::string username);
    std::string getUsername();
    void listBooks();
    void returnBook(const Spot spot, Bookshelf *shelf);
    void takeBook(const std::string& title, Bookshelf *shelf, bool copy);
  private:
    std::string username;
    std::map<Spot, Book> basket;
};

#endif