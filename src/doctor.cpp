#include <cstring>
#include <iostream>
#include "doctor.h"

// Default constructor
Doctor::Doctor(){
    Employee();
    doctorTitle = Intern;
}

Doctor::Doctor(int employeeID, int telephoneNumber, int annualSalary, const char *firstName, const char *lastName, char const *address, char const *email, title doctorTitle) 
                : doctorTitle(doctorTitle), Employee(employeeID, telephoneNumber, annualSalary, firstName, lastName, address, email) {}

const char *Doctor::getTitle(){

    switch(doctorTitle){
        case 0:
            return "Intern";
            break;
        case 1:
            return "Practitioner";
            break;
        case 2:
            return "Assistant";
            break;
        case 3:
            return "Specialist";
            break;
        case 4:
            return "Docent";
            break;
        case 5:
            return "Professor";
            break;
    }
    return NULL;
}