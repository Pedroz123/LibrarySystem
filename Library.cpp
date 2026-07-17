#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>


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

// const in string because "13224-123123-123" wont compile 
// without const you can only pass a real modifable string variable

void Library::returnBook(const std::string& isbn) {
    for (auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) {
            if (currentBook.getAvailable()) {
                std::cout << "The book is return already!" << "\n";
            } else {
                currentBook.setAvailable(true);
                std::cout << "The book return is successful" << "\n";
            }
            return;
        }
    }
    throw std::runtime_error("Book not found!"); // emergency
}


void Library::borrowBook(const std::string& isbn) {
    for (auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) {
            if (currentBook.getAvailable()) {
                std::cout << "Enjoy the book!" << "\n";
                currentBook.setAvailable(false);
            } else {
                std::cout << "The book is not available right now" << "\n";
            }
            return;
        }
    }
    throw std::runtime_error("Book not found!"); // emergency
}

void Library::eraseBook(const std::string& isbn) {
    for (auto& currentBook : this-> arr) {
        if (currentBook.getISBN() == isbn) {
            arr.erase(std::find(arr.begin(), arr.end(), currentBook));
            arr.pop_back();
        }
    }
}




void Library::setBook(Book& myBook) {arr.push_back(myBook);}


