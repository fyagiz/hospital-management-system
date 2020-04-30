#include <cstring>
#include <iostream>
#include "admin.h"

Admin::Admin(){
    Employee();
    aType = Secretary;
}

Admin::Admin(int employeeID, int telephoneNumber, int annualSalary, const char *firstName, const char *lastName, char const *address, char const *email, adminType title) 
                : aType(title), Employee(employeeID, telephoneNumber, annualSalary, firstName, lastName, address, email) {}
            
const char *Admin::getType(){

    switch(aType){
        case 0:
            return "Manager";
            break;
        case 1:
            return "Secretary";
            break;
        default:
            return NULL;
            break;
    }
}

void Admin::setType(adminType type){
    this->aType = type;
}

int Admin::anualSalaryCalculator(int hours){
    int newAnnualSalary = getAnnualSalary();

    if (!strcmp("Manager", getType())){
        newAnnualSalary += (hours * 50) * 52;
        setAnnualSalary(newAnnualSalary);
        return newAnnualSalary;
    }

    else{
        newAnnualSalary += (hours * 20) * 52;
        setAnnualSalary(newAnnualSalary);
        return newAnnualSalary;
    }
}