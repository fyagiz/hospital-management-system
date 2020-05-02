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

void Admin::overTimeSalaryCalculator(int hours){
    int newAnnualSalary = getAnnualSalary();

    if (!strcmp("Manager", getType())){
        newAnnualSalary += (hours * 50) * 52;
        setAnnualSalary(newAnnualSalary);
    }

    else{
        newAnnualSalary += (hours * 20) * 52;
        setAnnualSalary(newAnnualSalary);
    }
}

Admin &Admin::operator=(const Admin &existing_admin){
    
    if (this == &existing_admin){
        return *this;
    }
    
    employeeID = existing_admin.employeeID;
    telephoneNumber = existing_admin.employeeID;
    annualSalary = existing_admin.annualSalary;
    strcpy(firstName, existing_admin.firstName);
    strcpy(lastName, existing_admin.lastName);
    strcpy(address, existing_admin.address);
    strcpy(email, existing_admin.email);
    aType = existing_admin.aType;

    return *this;
}