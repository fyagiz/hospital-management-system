#ifndef DOCTOR_H
#define DOCTOR_H
#include "employee.h"

enum title {Intern, Practitioner, Assistant, Specialist, Docent, Professor};

class Doctor : public Employee{
    
    private:

        title doctorTitle;

    public:

        // Default constructor
        Doctor();
        // Specialized constructor
        Doctor(int, int, int, const char *, const char *, const char *, const char *, title);

        // Getter and Setter Functions
        const char *getTitle();
};

#endif