#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>


#include "Book.h"
#include "Member.h"
#include "Library.h"

//Default
    // Member Initializer List
Library::Library()
    : arr({}),
    usersArr({}) {}

//Parameterized constructor
    // Member Initializer List
Library::Library(const std::vector<Book>& arr, const std::vector<Member>& usersArr)
    : arr(arr),
    usersArr(usersArr) {}

//Getters

    // Book
Book Library::getBook(const std::string& isbn) const {
    for (const auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) return currentBook;
    }
    throw std::runtime_error("Book not found!"); // emergency
}

bool Library::isbnExists(const std::string& isbn) {
    for (const auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) return false;
    }
    return true;
}


    //Member
bool Library:: idExists(int id) {
    if (id <= 0) return false;
    if (this->usersArr.size() == 0) return false;
    for (const auto& currentId : this->usersArr) {
        if (currentId.getId() == id) return true;
    }
    return false;
}

Member& Library::getUser(int id)  {
    if (id <= 0) throw std::invalid_argument("Only positive numbers!");
    for (auto& currentUser : this->usersArr) {
        if (currentUser.getId() == id) return currentUser;
    }
    throw std::runtime_error("User not found!"); // emergency
}

//Setters

// const in string because "13224-123123-123" wont compile 
// without const you can only pass a real modifable string variable

void Library::returnBook(const std::string& isbn, int id) {    
    auto& currentMember = getUser(id);

    currentMember.eraseBorrowedBook(isbn);

    for (auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) {
            if (currentBook.getAvailable()) {
                throw std::invalid_argument("The book is already return!");
            } else {
                currentBook.setAvailable(true);
                
            }
            return;
        }
    }
    throw std::runtime_error("Book not found!"); // emergency
}


void Library::borrowBook(const std::string& isbn, int id) {
    for (auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) {
            if (currentBook.getAvailable()) {
                currentBook.setAvailable(false);

                auto& currentUser = getUser(id);
                currentUser.addBook(isbn);

            } else {
                throw std::invalid_argument("The book is not available right now");
            }
            return;
        }
    }
    // type const char  
    throw std::runtime_error("Book not found!"); // emergency
}


//Erase-Remove Idiom  O(n)
// https://stackoverflow.com/questions/74724178/how-to-delete-an-element-from-a-vector-of-custom-objects
// https://www.geeksforgeeks.org/cpp/erase-remove-idiom-in-cpp/
void Library::eraseBook(const std::string& isbn) {
    /*
    arr.erase(std::remove_if(arr.begin(), arr.end(), [isbn](const Book &b) {
        return b.getISBN() == isbn;
    }), arr.end());
    */
    auto removePoint = std::remove_if(arr.begin(), arr.end(), [&isbn](const Book &b) {
        return b.getISBN() == isbn;
    });

   if (removePoint == arr.end()) throw std::runtime_error("Book not found!"); // emergency
    arr.erase(removePoint, arr.end());
}


void Library::addBook(const Book& myBook) {arr.push_back(myBook);}
void Library::AddUser(const Member& myUser) {usersArr.push_back(myUser);}




//display
void Library::displayAllBooks() const {
    for (const auto &currentBook : this->arr) {currentBook.display();}
}

void Library::displayAllUsers() const {

    for (const auto& currentUser : this->usersArr) {currentUser.display();}
}


/*
void Library::returnBook(const std::string& isbn, int id) {
    for (auto& currentBook : this->arr) {
        if (currentBook.getISBN() == isbn) {
            if (currentBook.getAvailable()) {
                throw std::invalid_argument("The book is already return!");
            } else {
                currentBook.setAvailable(true);
                

            }
            return;
        }
    }
    throw std::runtime_error("Book not found!"); // emergency
}

*/