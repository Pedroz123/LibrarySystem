#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>




class Member{
    private:

    std::string userName;
    int id;
    std::vector<std::string> borrowedBooks;
    
    public:

    //Default
    Member();

    //Parameteraized constructor
    Member(const std::string& userName, int id, const std::vector<std::string>& borrowedBooks);

    //Getters
    std::string getUserName() const;
    int getId() const;
    std::vector<std::string> getBorredBooks() const;

    //Setters
    void setUserName(const std::string& userName);
    void setId(int id);
    void addBook(const std::string& borrowedBook);
    void eraseBorrowedBook(std::string isbn);

    //display
    void display() const;

};

#endif
