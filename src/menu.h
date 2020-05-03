#ifndef MENU_H
#define MENU_H

#include "employee.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"
#include "team.h"
#include "hospital.h"

class Menu{

    public:
        char showMenu(char, Hospital *); // This function operates menu.
        void createTeamMenu(Hospital *); // This function operates Create Team Menu.
        void searchMemberByIDMenu(Hospital *); // This function operates Search Member By ID Menu
        void listAllMembersMenu(Hospital *); // This function operates listing all members menu.
        void listTotalAnnualSalaryMenu(Hospital *); // This function operates listing total annual salary menu.
        void listAllMembersOfGivenTeamMenu(Hospital *); // This function operates listing all members of a given team menu.
        void listTotalAnnualSalaryOfGivenTeam(Hospital *); // This function operates listing total annual salary of a given team menu.
        void getEmployeeInfo(Employee *); // This function takes employee information from user.
        void addNewDoctor(Team *); // This function adds new doctor into the team.
        void addNewNurse(Team *); // This function adds new nurse into the team.
        void addNewAdmin(Team *); // This function adds new admin into the team.
};


#endif