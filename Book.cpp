#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>


#include "Book.h"

Book::Book() {
    title = "No name";
    author = "No author";
    year = 0;
    genre = "No genre";
    isbn = "0000000000";
    available = true;
}


Book::Book(std::string title, std::string author, int year, 
        std::string genre, std::string isbn, bool available) {
        this-> title = title;
        this-> author = author;
        this-> year = year;
        this-> genre = genre;
        this-> isbn = isbn;
        this-> available = available;
}


//Getters
std::string Book::getTitle() const {return title;}
std::string Book::getAuthor() const {return author;}
int Book::getYear() const {return year;}
std::string Book::getGenre() const {return genre;}
std::string Book::getISBN() const {return isbn;}
bool Book::getAvailable() const {return available;}


//Setters
void Book::setTitle(const std::string& title) {this -> title = title;}
void Book::setAuthor(const std::string& author) {this->author = author;}
void Book::setYear(int year) {this->year = year;}
void Book::setGenre(const std::string& genre) {this->genre = genre;}
void Book::setISBN(const std::string& isbn) {this-> isbn = isbn;}
void Book::setAvailable(bool available) {this-> available = available;}


void Book::display() {
    std::cout << "Name: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Year: " << year << "\n";
    std::cout << "Genre: " << genre << "\n";
    std::cout << "ISBN: " << isbn << "\n";
    std::cout << "Availability: " << available << "\n";
}



/*

class Book {
    private:
    std::string name;
    std::string author;
    int year;
    std:: string genre;
    std::string isbn;
    std::string available = "YES";

    public:

    Book(std::string name, std::string author, int year, 
        std::string genre, std::string isbn, std::string available) {
        this-> name = name;
        this-> author = author;
        this-> year = year;
        this-> genre = genre;
        this-> isbn = isbn;
        this-> available = available;
    }

    std::string getTitle() {return name;}
    std::string getGenre() {return genre;}
    std::string getAuthor() {return author;}
    std::string getISBN() {return isbn;}
    int getYear() {return year;}

    void setAvailable(bool available) {this-> available = available;}

    std::string isAvailable() {return available;}
    void display() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Genre: " << genre << "\n";
        std::cout << "ISBN: " << isbn << "\n";
        std::cout << "Availability: " << available << "\n";
    }

};

*/