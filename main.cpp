// a
#include <iostream>
#include <cmath>
#include <vector>

int validation(int myInput);
int main() {

    std::cout << "Hello this is a Library System ";
    int myInput = 3;
    while (true) {
        do {
            std::cout << "What do you need to do?  \n (1) Add Book \n(2) Show Books \n (3)Exit \n";
            std::cin >> myInput;
        } while (validation(myInput));

        switch (myInput) {
        case 1:
            // add function
            break;
        case 2: 
            // show books
            break;
        default:
            // exit            
            break;
        }
    }
    
    return 0;

}


int validation(int myInput) {
    return (myInput == 1) || (myInput == 2) || (myInput == 3);
}