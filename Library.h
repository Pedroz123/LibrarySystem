#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>

#include "Book.h"
#include "Members.h"

class Library {
    private:
    std::vector<Book> arr;
    std::vector<Members> usersArr;
    
    public:

    //Default
    Library();

    //Parameterized constructor
    Library(const std::vector<Book>& newArr, const std::vector<Members>& usersArr);

    //Getters
    Book getBook(const std::string& isbn) const;
    bool isbnExists(const std::string& isbn);
    Members getUser(int id) const;

    //Setters
    void addBook(const Book& myBook);
    void returnBook(const std::string& isbn);
    void borrowBook(const std::string& isbn);
    void eraseBook(const std::string& isbn);
    void AddUser(const Members& myUser);



    //display
    void displayAllBooks() const;
    void displayAllUsers() const;
};



#endif



