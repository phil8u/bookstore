#include <string>
#include <map>
#include <iostream>

#include <user.h>
#include <book.h>
#include <bookshelf.h>

using namespace std;

User::User() : username("") {
  basket[Spot::Left] = Book();
  basket[Spot::Middle] = Book();
  basket[Spot::Right] = Book();
};

User::User(std::string username) : username(username) {
  basket[Spot::Left] = Book();
  basket[Spot::Middle] = Book();
  basket[Spot::Right] = Book();
};

std::string User::getUsername() {
  return username;
};

void User::returnBook(const Spot spot, Bookshelf *shelf) {
  auto book = basket[spot];
  auto title = book.title;

  if (book.isEmpty()) {
    std::cout << "\033[93m" << "There is no book to return at the given spot." << "\033[0m" << std::endl;
    return;
  }
  try {
    shelf->putBook(book);
    std::cout << "\033[92m" << "Book successfully returned." << "\033[0m" << std::endl;
  }
  catch (char const* e) {
    std::cerr << "\033[91m" << e << "\033[0m" << std::endl;
  }
};

void User::takeBook(const string& title, Bookshelf *shelf, bool copy) {
  Spot spot;
  auto freeSpot = false;
  for (auto s = basket.begin(); s != basket.end(); s++) {
    if (s->second.isEmpty()) {
      spot = s->first;
      freeSpot = true;
      break;
    }
  }
  if (!freeSpot) {
    std::cout << "\033[93m" << "No space in basket, return books first." << "\033[0m"  << std::endl;
    return;
  }
  try {
    if (copy) {
      basket[spot] = shelf->getBook(title);
    } else {
      basket[spot] = std::move(shelf->getBook(title));
    }
  } catch (char const* e) {
    std::cerr << "\033[91m" << e << "\033[0m" << std::endl;
    return;
  }
  std::cout << "\033[92m" << "Book successfully taken." << "\033[0m" << std::endl;
};
    
void User::listBooks() {
  std::cout << basket[Spot::Left].title << ", "
    << basket[Spot::Middle].title << ", "
    << basket[Spot::Right].title << std::endl;
};
