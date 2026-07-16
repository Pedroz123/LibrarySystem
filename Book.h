#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

class Book {
    private:
    std::string title;
    std::string author;
    int year;
    std:: string genre;
    std::string isbn;
    bool available;

    public:
    //Default
    Book();
    // Parameterized constructor
    Book(std::string name, std::string author, int year, 
        std::string genre, std::string isbn, bool available);
    
    //Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getGenre() const;
    std::string getISBN() const;
    bool getAvailable() const;
// const == this method is read-only.It will not change any variable
    
    // Setters
    void setTitle(std::string& title);
    void setAuthor(std::string& author);
    void setYear(int year); 
    void setGenre(std::string& genre);
    void setISBN(std::string& isbn);
    void setAvailable(bool available);


    // prints all the private variables
    void display();

};



#endif
