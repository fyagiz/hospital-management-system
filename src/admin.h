#ifndef ADMIN_H
#define ADMIN_H
#include "employee.h"

enum adminType {Manager, Secretary};

class Admin : public Employee{

    private:

        adminType aType;
    
    public:
        // Default constructor
        Admin();
        // Specialized constructor
        Admin(int, int, int, const char *, const char *, const char *, const char *, adminType);

        // Getter and Setter Functions
        const char *getType();
        void setType(adminType);

        // Annual Salary Calculator
        void overTimeSalaryCalculator(int);

        // Assignment Operator
        Admin &operator=(const Admin &);

};

#endif