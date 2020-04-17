#include <cstring>
#include "employee.h"

// Default constructor
Employee::Employee(){
    
    employeeID = -1;
    telephoneNumber = -1;
    annualSalary = -1;

    firstName = new char[100];
    lastName = new char[100];
    address = new char[100];
    email = new char[100];

    strcpy(this->firstName, "null first name");
    strcpy(this->lastName, "null last name");
    strcpy(this->address, "null address");
    strcpy(this->email, "null email");

}

// Specialized constructor
Employee::Employee(int employeeID, int telephoneNumber, int annualSalary, char *firstName, char *lastName, char *address, char *email){

    this->employeeID = employeeID;
    this->telephoneNumber = telephoneNumber;
    this->annualSalary = annualSalary;

    this->firstName = new char[100];
    this->lastName = new char[100];
    this->address = new char[100];
    this->email = new char[100];

    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
    strcpy(this->address, address);
    strcpy(this->email, email);

}

// Setteers
void Employee::setEmployeeID(int employeeID){
    this->employeeID = employeeID;
}

void Employee::setTelephoneNumber(int telephoneNumber){
    this->telephoneNumber = telephoneNumber;
}

void Employee::setAnnualSalary(int annualSalary){
    this->annualSalary = annualSalary;
}

void Employee::setFirstName(char *firstName){
    strcpy(this->firstName, firstName);
}

void Employee::setLastName(char *lastName){
    strcpy(this->lastName, lastName);
}

void Employee::setAddress(char *address){
    strcpy(this->address, address);
}

void Employee::setEmail(char *email){
    strcpy(this->email, email);
}

// Getters
int Employee::getEmployeeID(){
    return employeeID;
}

int Employee::getTelephoneNumber(){
    return telephoneNumber;
}

int Employee::getAnnualSalary(){
    return annualSalary;
}

char *Employee::getFirstName(){
    return firstName;
}

char *Employee::getLastName(){
    return lastName;
}

char *Employee::getAddress(){
    return address;
}

char *Employee::getEmail(){
    return email;
}

// Destructor
Employee::~Employee(){
    delete[] firstName;
    delete[] lastName;
    delete[] address;
    delete[] email;
}