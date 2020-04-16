#include <iostream>

/*
                                                            Furkan Yagiz 2152197
                                                    CNG 242 Programming Language Concepts
                                                Assignment 2 (C++): Hospital Management System
*/

// Function prototypes
void menu();

int main(){

    menu();

    return 0;
}

void menu(){
    char command;

    std::cout << "Welcome to Hospital Management System!" << std::endl;

    do{
        std::cout << "1. Create a team" << std::endl;
        std::cout << "2. Search a member by ID" << std::endl;
        std::cout << "3. List all members" << std::endl;
        std::cout << "4. List total annual salary" << std::endl;
        std::cout << "5. List all members of a given team" << std::endl;
        std::cout << "6. List total annual salary of a given team" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your selection: ";
        std::cin >> command;

        switch(command){
            
            case '1':
                std::cout << "1" << std::endl;
                break;
            case '2':
                std::cout << "2" << std::endl;
                break;
            case '3':
                std::cout << "3" << std::endl;
                break;
            case '4':
                std::cout << "4" << std::endl;
                break;
            case '5':
                std::cout << "5" << std::endl;
                break;
            case '6':
                std::cout << "6" << std::endl;
                break;
            case '7':
                std::cout << "Goodbye!" << std::endl;
                break;

        };

    }while (command != '7');
}