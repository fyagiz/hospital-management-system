#ifndef DOCTOR_H
#define DOCTOR_H
#include "employee.h"

enum doctorTitle {Intern, Practitioner, Assistant, Specialist, Docent, Professor};

class Doctor : public Employee{
    
    private:

        doctorTitle dTitle;

    public:

        // Default constructor
        Doctor();
        // Specialized constructor
        Doctor(int, int, int, const char *, const char *, const char *, const char *, doctorTitle);

        // Getter and Setter Functions
        const char *getTitle();
        void setTitle(doctorTitle);
};

#endif