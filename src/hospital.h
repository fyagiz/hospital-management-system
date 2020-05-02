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
        
        // Destructor
        ~Hospital();

        // Add New Team
        int addNewTeam(int);
        //  Search for the details of a given employeeID
        void employeeSearchByID(int);
        //  Get team with teamID
        Team *getTeamByID(int);
        // List All Members
        void listAllMembers();
        // Total Annual Salary
        int totalAnnualSalary();
        // List all members of a given team
        void listAllMembersOfGivenTeam(int);
        // List total annual salary of a given team
        int listTotalAnnualSalaryOfGivenTeam(int);

};

#endif