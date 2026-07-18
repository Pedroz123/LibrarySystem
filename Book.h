#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>


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
    // const because getters generally should not change the object this allows us to keep the class "const-correct"
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getGenre() const;
    std::string getISBN() const;
    bool getAvailable() const;
// const == this method is read-only.It will not change any variable
    
    // Setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setYear(int year); 
    void setGenre(const std::string& genre);
    void setISBN(const std::string& isbn);
    void setAvailable(bool available);


    // prints all the private variables
    void display();

};



#endif
