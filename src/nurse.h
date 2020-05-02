#ifndef NURSE_H
#define NURSE_H
#include "employee.h"

enum nurseTitle {General, Midwife};

class Nurse : public Employee{

    private:
        nurseTitle nTitle;
    
    public:

        // Default constructor
        Nurse();
        // Specialized constructor
        Nurse(int, int, int, const char *, const char *, const char *, const char *, nurseTitle);

        // Getter and Setter Functions
        const char *getTitle();
        void setTitle(nurseTitle);

        // Annual Salary Calculator
        void overtimeAnnualSalaryCalculate(int);

        // Assignment Operator
        Nurse &operator=(const Nurse &);

};

#endif