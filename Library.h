#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#include "Book.h"

class Library {
    private:
    std::vector<Book> arr;

    
    public:

    //Default
    Library();

    //Parameterized constructor
    Library(std::vector<Book> new_arr);

    //Getters
    Book getBook(std::string& isbn) const;

    //Setters
    void setBook(Book& myBook);
    void returnBook(const std::string& isbn);
    void borrowBook(const std::string& isbn);
    void eraseBook(const std::string& isbn);

};



#endif



