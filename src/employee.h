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
        Employee(int, int, int, const char *, const char *, const char *, const char *);
        // Setters
        void setEmployeeID(int);
        void setTelephoneNumber(int);
        void setAnnualSalary(int);
        void setFirstName(const char *);
        void setLastName(const char *);
        void setAddress(const char *);
        void setEmail(const char *);
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