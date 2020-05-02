#include <cstring>
#include <iostream>
#include <typeinfo>
#include "team.h"
#include "admin.h"
#include "doctor.h"
#include "employee.h"
#include "nurse.h"
#include "hospital.h"

// Default constructor
Hospital::Hospital(){

    teams = new Team [100];
}

// Destructor
Hospital::~Hospital(){
    delete[] teams;
}

// Add New Team
int Hospital::addNewTeam(int teamID){
    int i;
    for (i=0;i<100;i++){
        if(teams[i].getTeamID() == -1){
            teams[i].setTeamID(teamID);
            return i;
            break;
        }
    }

    return -1;
}

// Search for the details of a given employeeID
void Hospital::employeeSearchByID(int employeeID){
    int i;

    for (i=0;i<100;i++){
        if(teams[i].getTeamID() == -1){
            break;
        }
        else{
            if(teams[i].searchEmployeeByEmployeeID(employeeID))
                break;
        }
    }
}

// Get team with teamID
Team *Hospital::getTeamByID(int teamID){
    int i;
    Team *temp = new Team();
    for(i=0;i<100;i++){
        if(teams[i].getTeamID() == teamID){
            return &teams[i];
            break;
        }
    }

    return temp;
}

// List All Members
void Hospital::listAllMembers(){
    int i;
    for(i=0;i<100;i++){
        if (teams[i].getTeamID() != -1){
            teams[i].listLeaderAndMembers();
        }
        else if(teams[i].getTeamID() == -1){
            break;
        }
    }
}

// Total Annual Salary
int Hospital::totalAnnualSalary(){
    int i;
    int total;

    total = 0;
    for(i=0;i<100;i++){
        if (teams[i].getTeamID() != -1){
            total += teams[i].teamAnnualCostCalculator();
        }
        else if(teams[i].getTeamID() == -1){
            break;
        }
    }

    return total;
}

// List all members of a given team
void Hospital::listAllMembersOfGivenTeam(int teamID){
    Team *tmp = getTeamByID(teamID);
    if (tmp->getTeamID() != -1)
        tmp->listLeaderAndMembers();
    else
        std::cout << "The team is not found! Team ID: " << teamID << std::endl;
    
}

// List total annual salary of a given team
int Hospital::listTotalAnnualSalaryOfGivenTeam(int teamID){
    Team *tmp = getTeamByID(teamID);
    if (tmp->getTeamID() != -1)
        return tmp->teamAnnualCostCalculator();
    else{
        std::cout << "The team is not found! Team ID: " << teamID << std::endl;
        return 0;
    }
}

// Get Teams
Team *Hospital::getTeams(){
    return this->teams;
}