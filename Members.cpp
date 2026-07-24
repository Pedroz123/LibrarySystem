#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>

#include "Members.h"


//Default
Members::Members() {
    userName = "";
    id = 0;
    borrowedBooks = {};
}


//Parameteraized constructor
Members::Members(const std::string& userName, int id, const std::vector<std::string>& borrowedBooks) {
    this-> userName = userName;
    this-> id = id;
    this-> borrowedBooks = borrowedBooks;
}


//Getters
std::string Members::getUserName() const {return userName;}
int Members::getId() const {return id;}
std::vector<std::string> Members::getBorredBooks() const {return borrowedBooks;}


//Setters
void Members::setUserName(const std::string& userName) {this-> userName = userName;}
void Members::setId(int id) {this->id = id;}


//Display
void Members::display() const {
    std::cout << "User name: " << userName << "\n"
        << "ID: " << id << "\n"
        << "Borrowed Books: " <<"\n";
    for (const auto& book : borrowedBooks) std::cout << book << "\n";

}
