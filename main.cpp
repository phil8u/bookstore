#include <iostream>
#include <chrono>
#include <thread>
#include <chrono>

#include <user.h>
#include <bookshelf.h>

std::string welcome() {
  std::string username;
  std::cout << "Please enter your name:" << std::endl;
  std::cin >> username;
  std::cout << "Hello " << username << "!" << std::endl;
  return username;
}

void initBooks(Bookshelf* shelf) {
  auto example = Book("Ex1", "Max Mustermann", 500020500);
  auto example2 = Book("ExampleTitle", "Max Mustermann", 400);
  auto example3 = Book("Ex3", "Max Mustermann", 100200);
  shelf->putBook(example);
  shelf->putBook(example2);
  shelf->putBook(example3);
}

float bookSelectionWithTimer(User &user, std::string& booktitle, Bookshelf &bookshelf, bool copy) {
  clock_t start_time = std::clock();
  user.takeBook(booktitle, &bookshelf, copy);
  clock_t end_time = std::clock();
  float diff = static_cast<float>(end_time - start_time);
  diff /= CLOCKS_PER_SEC;
  return diff;
}

int main(int argc,char** argv) {
  bool loggedIn = false;
  User user;
  std::string username;
  Bookshelf bookshelf(5, 10);
  initBooks(&bookshelf);
  while (true) {
    if (loggedIn) {
      int action;
      std::string booktitle;
      int spot_input;
      Spot spot;
      float time_diff;
      std::cout << "\nWelcome to the library!" << std::endl;
      std::cout << "Books in your Basket: ";
      user.listBooks();
      std::cout << "\nSelect an option:" << std::endl;
      std::cout << "\t[1] Borrow a book" << std::endl;
      std::cout << "\t[2] Bring back a book" << std::endl;
      std::cout << "\t[3] Leave the library" << std::endl;
      std::cin >> action;
      std::cout << std::endl;
      switch (action) {
      case 1:
        std::cout << "Please enter a booktitle:" << std::endl;
        std::cin >> booktitle;
        // Trying to Copy
        // time_diff = bookSelectionWithTimer(user, booktitle, bookshelf, true);
        // std::cout << "Copying of the Book needed: " << 1000*time_diff << " milliseconds \n";
        // Moving the same book
        time_diff = bookSelectionWithTimer(user, booktitle, bookshelf, false);
        std::cout << "Moving of the Book needed: " << 1000*time_diff << " milliseconds \n";
        break;
      case 2:
        std::cout << "Please enter the basket spot of the book you want to return (0-2)" << std::endl;
        std::cin >> spot_input;
        spot = static_cast<Spot>(spot_input);
        user.returnBook(spot, &bookshelf);
        break;
      case 3:
        std::cout << "Goodbye!\n\n" << std::endl;
        loggedIn = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        break;
      default:
        std::cout << "\033[91m" << "Action is invalid" << "\033[0m" << std::endl;
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      username = welcome();
      if (username != "") {
        user = User(username);
        loggedIn = true;
      }
    }
  }
  
  return 0;
}
