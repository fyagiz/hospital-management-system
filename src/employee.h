#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{

    private:

        int employeeID;
        int telephoneNumber;
        int annualSalary;
        char *firstName;
        char *lastName;
        char *address;
        char *email;

    public:

        // Default constructor
        Employee();
        // Specialized constructor
        Employee(int, int, int, char *, char *, char *, char *);
        // Setters
        void setEmployeeID(int);
        void setTelephoneNumber(int);
        void setAnnualSalary(int);
        void setFirstName(char *);
        void setLastName(char *);
        void setAddress(char *);
        void setEmail(char *);
        // Getters
        int getEmployeeID();
        int getTelephoneNumber();
        int getAnnualSalary();
        char *getFirstName();
        char *getLastName();
        char *getAddress();
        char *getEmail();
        // This function will show the employee's information
        void showEmployeeInfo();
        // Destructor
        ~Employee();
};


#endif