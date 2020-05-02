#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "admin.h"
#include "doctor.h"
#include "employee.h"
#include "nurse.h"
#include "team.h"


class Hospital{

    private: 
        Team *teams;
    
    public:
            // Default constructor
        Hospital();
};

#endif