#include <iostream>
#include <cstring>
#include "employee.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"
#include "team.h"
#include "hospital.h"
#include "menu.h"
/*
                                                            Furkan Yagiz 2152197
                                                    CNG 242 Programming Language Concepts
                                                Assignment 2 (C++): Hospital Management System
*/


int main(){
    
    Hospital *hospital = new Hospital();
    Menu menu;
    char command;

    do{
        command = menu.showMenu(command, hospital);
    }while (command != '7');

    return 0;
}