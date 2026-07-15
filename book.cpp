#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class AbstractBook {
    private:
    //virtual void uniqueBook() = 0;
    virtual void availableBook() = 0;
    // virtual: "check and execute the most derive part of the this function"
};
class Book: AbstractBook{
    private:
    std::string name;
    std::string author;
    int year;
    std:: string genre;
    std::string isbn;
    bool available = true;

    public:

    Book(std::string name, std::string author, int year, 
        std::string genre, std::string isbn, bool available) {
        this-> name = name;
        this-> author = author;
        this-> year = year;
        this-> genre = genre;
        this-> isbn = isbn;
        this-> available = available;
    }

    std::string getTitle() {return name;}
    std::string getGenre() {return genre;}
    void setAvailable(bool available) {this-> available = available;}
    bool isAvailable() {return available;}
    void infoBook() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Genre: " << genre << "\n";
        std::cout << "ISBN: " << isbn << "\n";
        std::cout << "Availability: " << available << "\n";
    }
    void availableBook() {
        if (available) {
            std::cout << "This book is available" << "\n";
        } else {
            std::cout << "This book is NOT available" << "\n";
        }
    }
};