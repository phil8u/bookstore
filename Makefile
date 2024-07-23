
bookstore: main.o user.o bookshelf.o book.o
	g++ main.o user.o bookshelf.o book.o -o bookstore

main.o: main.cpp include/user.h include/book.h
	g++ -c main.cpp -std=c++20 -Iinclude

user.o: lib/user.cpp include/user.h
	g++ -c lib/user.cpp -std=c++20 -Iinclude

bookshelf.o: lib/bookshelf.cpp include/bookshelf.h include/book.h
	g++ -c lib/bookshelf.cpp -std=c++20 -Iinclude

book.o: lib/book.cpp include/book.h
	g++ -c lib/book.cpp -std=c++20 -Iinclude

