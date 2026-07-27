// TO RUN THE PROGRAM: g++ *.cpp -o run

IMPORTANT:
    std::ws removes leading whitespace
    getline() reads spaces
    remove_if doesn't erase elements
    erase-remove idiom requieres calling erase() after remove_if()
    Passing std::string by const reference avoids copies



//Parameterized constructor
Two aproaches
->> Assignment in the Body(First Snippst)
    Book::Book(std::string title, std::string author, int year, 
        std::string genre, std::string isbn, bool available) {
        this-> title = title;
        this-> author = author;
        this-> year = year;
        this-> genre = genre;
        this-> isbn = isbn;
        this-> available = available;
    }
Two steps 
Creates the default-initializes every member variable
Then inside {} body, it overwrites those empty values using the assignmet = operator

DOWNSIDES
    Double work
    Clunky syntax this-> title
    Won't always compile with const and reference members


->> Member Initializer List

Book::Book(std::string title, std::string author, int year, 
        std::string genre, std::string isbn, bool available) 
    : 
    title(title),
    author(author),
    year(year),
    genre(genre),
    isbn(isbn),
    available(available) {

    }
UPSIDES
Members are constructed directly using the arguments provided before the constructor body {} runs

BETTER PERFORMANCE 
NO NAME COLLISION
WORKS FOR EVERYTHING