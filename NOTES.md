Things i learned:
    std::ws removes leading whitespace
    getline() reads spaces
    remove_if doesn't erase elements
    erase-remove idiom requieres calling erase() after remove_if()
    Passing std::string by const reference avoids copies