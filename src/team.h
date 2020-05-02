#ifndef TEAM_H
#define TEAM_H
#include "admin.h"
#include "doctor.h"
#include "employee.h"
#include "nurse.h"


class Team{
    
    private:

        int teamID;
        int size;
        Doctor *teamLeader;
        Admin *adminList;
        Doctor *doctorList;
        Nurse *nurseList;
        
    public: 
        
        // Default constructor
        Team();
        // Specialized constructor
        Team(int);

        // Getter and Setter Functions
        int getTeamID();
        Doctor *getTeamLeader();
        void setTeamID(int);
        void setTeamLeader(Doctor *);

        // Add a new team member function
        void addDoctorToTeam(Doctor *);
        void addNurseToTeam(Nurse *);
        void addAdminToTeam(Admin *);

        // List the team leader and the members function
        void listLeaderAndMembers();

        // Annual Cost Calculator
        int teamAnnualCostCalculator();

        // Search employee function
        bool searchEmployeeByEmployeeID(int);

        // Destructor
        ~Team();
};

#endif