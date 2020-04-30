#include <cstring>
#include <iostream>
#include "employee.h"

// Default constructor
Employee::Employee(){
    
    employeeID = -1;
    telephoneNumber = -1;
    annualSalary = -1;

    int size;

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
Employee::Employee(int employeeID, int telephoneNumber, int annualSalary, const char *firstName, const char *lastName, const char *address, const char *email){

    this->employeeID = employeeID;
    this->telephoneNumber = telephoneNumber;
    this->annualSalary = annualSalary;

    this->firstName = new char[strlen(firstName)];
    this->lastName = new char[strlen(lastName)];
    this->address = new char[strlen(address)];
    this->email = new char[strlen(email)];

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

void Employee::setFirstName(const char *firstName){
    strcpy(this->firstName, firstName);
}

void Employee::setLastName(const char *lastName){
    strcpy(this->lastName, lastName);
}

void Employee::setAddress(const char *address){
    strcpy(this->address, address);
}

void Employee::setEmail(const char *email){
    strcpy(this->address, email);
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

// This function will show the employee's information
void Employee::showEmployeeInfo(){
    std::cout << "Employee ID: " << employeeID << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Telephone number: " << telephoneNumber << std::endl;
    std::cout << "E-Mail: " << email << std::endl;
}

// Destructor
Employee::~Employee(){
    delete[] firstName;
    delete[] lastName;
    delete[] address;
    delete[] email;
}