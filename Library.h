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
#include "Member.h"

class Library {
    private:
    std::vector<Book> arr;
    std::vector<Member> usersArr;
    
    public:

    //Default
    Library();

    //Parameterized constructor
    Library(const std::vector<Book>& arr, const std::vector<Member>& usersArr);

    //Getters
    Book getBook(const std::string& isbn) const;
    bool isbnExists(const std::string& isbn);
    Member& getUser(int id);
    bool idExists(int id);
   // void printName(const std::string& isbn); 

    //Setters
    void addBook(const Book& myBook);
    void returnBook(const std::string& isbn, int id);
    void borrowBook(const std::string& isbn, int id);
    void eraseBook(const std::string& isbn);
    void AddUser(const Member& myUser);



    //display
    void displayAllBooks() const;
    void displayAllUsers() const;
};



#endif



