#include <iostream> // for std::cout, std::cin and std::endl;
#include <unistd.h> // for pause()

// function declaration
void welcome();

// function definition
void greet() {
    std::cout << "please input your name: " << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "hello, " << name << std::endl;

    return;
}

/*
main function
*/
int main() {
    greet();

    welcome();
    // // keep the console window open in debug mode
    // // use two std::cin.get() to wait for the second enter key
    // std::cin.get();
    // std::cin.get();

    pause(); // ctrl + c to exit
    return 0;

}