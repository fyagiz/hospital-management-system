#include <cstring>
#include <iostream>
#include "nurse.h"

Nurse::Nurse(){
    Employee();
    nTitle = General;
}

Nurse::Nurse(int employeeID, int telephoneNumber, int annualSalary, const char *firstName, const char *lastName, char const *address, char const *email, nurseTitle title) 
                : nTitle(title), Employee(employeeID, telephoneNumber, annualSalary, firstName, lastName, address, email) {}

const char *Nurse::getTitle(){

    switch(nTitle){
        case 0:
            return "General";
            break;
        case 1:
            return "Midwife";
            break;
        default:
            return NULL;
    }
}

void Nurse::setTitle(nurseTitle title){
    this->nTitle = title;
}

int Nurse::overtimeAnnualSalaryCalculate(int overTime){
    int newAnnualSalary = getAnnualSalary();

    if (!strcmp("General", getTitle())){
        newAnnualSalary += (overTime * 20) * 52;
        setAnnualSalary(newAnnualSalary);
        return newAnnualSalary;
    }

    else{
        newAnnualSalary += (overTime * 30) * 52;
        setAnnualSalary(newAnnualSalary);
        return newAnnualSalary;
    }
}