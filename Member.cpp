#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>

#include "Member.h"


//Default
Member::Member() {
    userName = "";
    id = 0;
    borrowedBooks = {};
}


//Parameteraized constructor
Member::Member(const std::string& userName, int id, const std::vector<std::string>& borrowedBooks) {
    this-> userName = userName;
    this-> id = id;
    this-> borrowedBooks = borrowedBooks;
}


//Getters
std::string Member::getUserName() const {return userName;}
int Member::getId() const {return id;}
std::vector<std::string> Member::getBorredBooks() const {return borrowedBooks;}


//Setters
void Member::setUserName(const std::string& userName) {this-> userName = userName;}
void Member::setId(int id) {this->id = id;}
void Member::addBook(const std::string& borrowedBook) {this->borrowedBooks.push_back(borrowedBook);}
void Member::eraseBorrowedBook(std::string isbn) {
    auto removePoint = std::remove_if(borrowedBooks.begin(), borrowedBooks.end(), [&isbn](const std::string &b) {
        return b == isbn;
    });

   if (removePoint == borrowedBooks.end()) throw std::runtime_error("Book not found!"); // emergency
    borrowedBooks.erase(removePoint, borrowedBooks.end());
}

//Display
void Member::display() const {
    std::cout << "User name: " << userName << "\n"
        << "ID: " << id << "\n"
        << "Borrowed Books: ";

        if (borrowedBooks.size() == 0) {
            std::cout << "N/A" << "\n";
        } else {
            std::cout << "\n";
            for (const auto& book : borrowedBooks) std::cout << book << "\n";
        }

}
