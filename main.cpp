#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <exception>

#include "Book.h"
#include "Library.h"
#include "Members.h"

void borrowBook(Library &library);
void eraseBook(Library &library);
Book inputBook(Library& library);
Members inputUser (Library& library);
void returnBook(Library &library);
void searchBook(Library &library);
std::string getIsbn();
bool validation(int myInput);
int getNewId(Library& library);
int getRegularId() ;


// TO RUN THE PROGRAM: g++ *.cpp -o run
// NO ADD TO GIT THE RUN.txt FILE
int main() {
    Library library;
    std::cout << "Hello this is a Library System ";
    int myInput = 9;
    while (true) {
        
        do {
            std::cout << "What do you need to do? \n" 
            << "(1) Add new Book \n"
            << "(2) Show Books \n" 
            << "(3) Borrow Book \n" 
            << "(4) Retur Book \n"
            << "(5) Search Book \n"
            << "(6) Remove Book\n"
            << "(7) Add new user\n"
            << "(8) Show users\n"
            << "(9) Exit Book \n"
            << "--> ";
            std::cin >> myInput;
        } while (validation(myInput));


        switch (myInput) {
        case 1: {
            // add function
            Book currentBook = inputBook(library);
            library.addBook(currentBook);
            break;
        }
        case 2: {
            // show books
            library.displayAllBooks();
            break;
        }
        case 3: {            
            //Borrow books
            borrowBook(library);
            break;
        }
        case 4: {
            //Return book
            returnBook(library);
            break;
        }
        case 5: {
            //Search book
            searchBook(library);
            break;
        }
        case 6: {
            // erase book
            eraseBook(library);
            break;
        } 
        case 7: {
            Members newUser = inputUser(library);
            library.AddUser(newUser);
            break;
        } 
        case 8: {
            library.displayAllUsers();
            break;
        } 
        default:
            // exit            
            std::cout << "Goodbye" << "\n";
            
            return 0;
        }
    }
    
    return 0;

}


Book inputBook(Library& library) {
// https://www.geeksforgeeks.org/cpp/manipulators-in-c-with-examples/
    std::string name, author, genre, isbn, temp = "yes";
    int year;
    bool available;
    // std::ws to formating spacing and be able to use getline after a getliner or a cin 
    std::cout << "\nName of the book: ";
    getline(std::cin >> std::ws, name);
            
    std::cout << "\nAuthor of the book: " ;
    getline(std::cin >> std::ws, author);

    std::cout << "\nYear of publication: ";
    std::cin >> year;

    std::cout << "\nGenre: ";
    std::cin >> genre;

    do {
    std::cout << "\nISBN (ten digits): ";
    std::cin >> isbn;
    //std::cout << library.isAvailable(isbn);
    } while (!(library.isbnExists(isbn)));
    // check if the the isbn is the same
    //The class that owns the data should also enforce the rules about that data

        
    std::cout << "Is the book available (yes or no): ";
    std::cin >> temp;

    available  = (temp == "yes");
    Book currentBook(name, author, year, genre, isbn, available);
    return currentBook;

}


Members inputUser (Library& library) {
    std::string userName;
    int id;

    std::cout << "Hello there!! \n";
    std::cout << "Fill this information to create your account!!\n";
    std::cout << "User Name: ";
    getline(std::cin >> std::ws, userName);
    id  = getNewId(library);

    Members currentMember(userName, id, {});

    std::cout << "USER ADDED SUCCESFULLY \n";
    return currentMember;


}


void borrowBook(Library &library) {
    int id = -1;
    try {
        id = getRegularId();
        library.getUser(id);   
        library.borrowBook(getIsbn(), id);
        std::cout << "Enjoy your book!\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }


}


void returnBook(Library &library) {
    int id = -1;
    try {
        id = getRegularId();
        library.getUser(id);
        library.returnBook(getIsbn(), id);
        std::cout << "Thanks for returning the book!\n";
    }   catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}


void searchBook(Library &library) {
    try {
        /* code */
        auto currentBook = library.getBook(getIsbn());
        currentBook.display();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }    
}


void eraseBook(Library &library) {
    try {
        library.eraseBook(getIsbn());
        std::cout << "Book erased!\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}


std::string getIsbn() {
    std::string answer = "";
    std::cout << "\nISBN of the book (10 words): ";
    std::cin >> answer;
    return answer;
}


bool validation(int myInput) {
    return !(myInput >= 1 && myInput <= 10);
}


int getNewId(Library& library) {
    int id = 0;
    //std::cout << "Fill the next information: \n";
    while (true) {
        std::cout << "ID: ";
        std::cin >> id;
        if (id <= 0) {
            std::cout << "ID must be positive \n";
        } else if (library.idExists(id)) {
            std::cout << "ID already in use \n";
        } else {
            break;
        }
    }
    return id;
}


int getRegularId() {
    int id = -1;
    std::cout << "Enter ID: ";
    std::cin >> id;
    return id;
}