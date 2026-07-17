#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "Library.h"
#include "Book.h"

//Default
Library::Library() {arr = {};}

//Parameterized constructor
Library::Library(std::vector<Book> newArr) {this-> arr = newArr;}

//Getters
Book Library::getBook(std::string& isbn) const {
    for (const auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) return currentBook;
    }
    throw std::runtime_error("Book not found!"); // emergency
}

//Setters
void Library::setBook(Book& myBook) {arr.push_back(myBook);}


