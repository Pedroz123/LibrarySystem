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

class Library {
    private:
    std::vector<Book> arr;

    
    public:

    //Default
    Library();

    //Parameterized constructor
    Library(const std::vector<Book>& new_arr);

    //Getters
    Book getBook(const std::string& isbn) const;

    //Setters
    void addBook(const Book& myBook);
    void returnBook(const std::string& isbn);
    void borrowBook(const std::string& isbn);
    void eraseBook(const std::string& isbn);

    //display

    void displayAllBooks();
};



#endif



