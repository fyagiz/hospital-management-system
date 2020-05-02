#include <cstring>
#include <iostream>
#include <typeinfo>
#include "team.h"
#include "admin.h"
#include "doctor.h"
#include "employee.h"
#include "nurse.h"

int adminListSearch(Admin *, int);
int doctorListSearch(Doctor *, int);
int nurseListSearch(Nurse *, int);

int adminListAnnualCostCalculator(Admin *);
int doctorListAnnualCostCalculator(Doctor *);
int nurseListAnnualCostCalculator(Nurse *);

void adminListPrinter(Admin *);
void doctorListPrinter(Doctor *);
void nurseListPrinter(Nurse *);

Team::Team(){
    teamID = -1;
    size = 0;
    teamLeader = new Doctor();
    adminList = new Admin [25];
    doctorList = new Doctor [25];
    nurseList = new Nurse [25];
}

Team::Team(int teamID){
    this->teamID = teamID;
    size = 0;

    teamLeader = new Doctor();
    adminList = new Admin [25];
    doctorList = new Doctor [25];
    nurseList = new Nurse [25];

}

int Team::getTeamID(){
    return this->teamID;
}

Doctor *Team::getTeamLeader(){
    return this->teamLeader;
}

void Team::setTeamID(int teamID){
    this->teamID = teamID;
}

void Team::setTeamLeader(Doctor *newTeamLeader){

    if (!strcmp(newTeamLeader->getTitle(), "Intern") || !strcmp(newTeamLeader->getTitle(), "Practitioner") || !strcmp(newTeamLeader->getTitle(), "Assistant"))
        std::cout << "Team leader must be Specialist, Docent or Professor!" << std::endl;
    else
        this->teamLeader = newTeamLeader;
}

void Team::addDoctorToTeam(Doctor *addDoctor){
    int i=0;

    for (i=0;i<25;i++){
        if (doctorList[i].getEmployeeID() == -1){
            doctorList[i] = *addDoctor;
            break;
        }
    }
    size++;
}

void Team::addNurseToTeam(Nurse *addNurse){
    int i=0;

    for (i=0;i<25;i++){
        if (nurseList[i].getEmployeeID() == -1){
            nurseList[i] = *addNurse;
            break;
        }
    }
    size++;
}

void Team::addAdminToTeam(Admin *addAdmin){
    int i=0;

    for (i=0;i<25;i++){
        if (adminList[i].getEmployeeID() == -1){
            adminList[i] = *addAdmin;
            break;
        }
    }
    size++;
}

void Team::listLeaderAndMembers(){
    
    if (size == 0){
        std::cout << "The team is empty!" << std::endl;
    }

    else{
        int i;

        std::cout << "Team " << teamID << std::endl;

        std::cout << "Team Leader: " << std::endl;
        teamLeader->showEmployeeInfo();
        std::cout << "Team Members" << std::endl;
        adminListPrinter(adminList);
        doctorListPrinter(doctorList);
        nurseListPrinter(nurseList);

    }
}

int Team::teamAnnualCostCalculator(){
    int teamAnnualCost = 0;
    
    teamAnnualCost += teamLeader->getAnnualSalary();
    teamAnnualCost += adminListAnnualCostCalculator(adminList);
    teamAnnualCost += doctorListAnnualCostCalculator(doctorList);
    teamAnnualCost += nurseListAnnualCostCalculator(nurseList);

    return teamAnnualCost;
}

bool Team::searchEmployeeByEmployeeID(int employeeID){
    int aFlag;
    int dFlag;
    int nFlag;

    aFlag = adminListSearch(adminList, employeeID);
    dFlag = doctorListSearch(doctorList, employeeID);
    nFlag = nurseListSearch(nurseList, employeeID);

    if (teamLeader->getEmployeeID() == employeeID){

        std::cout << "It is found in team " << teamID << ". ";
        std::cout << "The details are listed below." << std::endl;
        teamLeader->showEmployeeInfo();
        
        return true;
    }

    else if(aFlag != -1){

        std::cout << "It is found in team " << teamID << ". ";
        std::cout << "The details are listed below." << std::endl;
        adminList[aFlag].showEmployeeInfo();
        
        return true;
    }

    else if(dFlag != -1){

        std::cout << "It is found in team " << teamID << ". ";
        std::cout << "The details are listed below." << std::endl;
        doctorList[dFlag].showEmployeeInfo();
        
        return true;
    }

    else if(nFlag != -1){

        std::cout << "It is found in team " << teamID << ". ";
        std::cout << "The details are listed below." << std::endl;
        nurseList[nFlag].showEmployeeInfo();
        
        return true;
    }
    
    else
        return false;
    
    
}

int adminListSearch(Admin *adminList, int employeeID){
    int i;
    
    for(i=0;i<25;i++){
        if (adminList[i].getEmployeeID() == -1)
            break;
        if(adminList[i].getEmployeeID() == employeeID){
            return i;
            break;
        }
    }

    return -1;
}

int doctorListSearch(Doctor *doctorList, int employeeID){
    int i;
    
    for(i=0;i<25;i++){
        if (doctorList[i].getEmployeeID() == -1)
            break;
        if(doctorList[i].getEmployeeID() == employeeID){
            return i;
            break;
        }
    }

    return -1;
}

int nurseListSearch(Nurse *nurseList, int employeeID){
    int i;
    
    for(i=0;i<25;i++){
        if (nurseList[i].getEmployeeID() == -1)
            break;
        if(nurseList[i].getEmployeeID() == employeeID){
            return i;
            break;
        }
    }

    return -1;
}

int adminListAnnualCostCalculator(Admin *adminList){
    int total = 0;
    int i;

    for(i=0;i<25;i++){
        if (adminList[i].getEmployeeID() == -1)
            break;
        else{
            total += adminList[i].getAnnualSalary();
        }
    }

    return total;
}

int doctorListAnnualCostCalculator(Doctor *doctorList){
    int total = 0;
    int i;

    for(i=0;i<25;i++){
        if (doctorList[i].getEmployeeID() == -1)
            break;
        else{
            total += doctorList[i].getAnnualSalary();
        }
    }

    return total;
}

int nurseListAnnualCostCalculator(Nurse *nurseList){
    int total = 0;
    int i;

    for(i=0;i<25;i++){
        if (nurseList[i].getEmployeeID() == -1)
            break;
        else{
            total += nurseList[i].getAnnualSalary();
        }
    }

    return total;
}

void adminListPrinter(Admin *adminList){
    int i;

    for(i=0;i<25;i++){
        if (adminList[i].getEmployeeID() == -1)
            break;
        else{
            adminList[i].showEmployeeInfo();
        }
    }
}

void doctorListPrinter(Doctor *doctorList){
    int i;

    for(i=0;i<25;i++){
        if (doctorList[i].getEmployeeID() == -1)
            break;
        else{
            doctorList[i].showEmployeeInfo();
        }
    }
}

void nurseListPrinter(Nurse *nurseList){
    int i;

    for(i=0;i<25;i++){
        if (nurseList[i].getEmployeeID() == -1)
            break;
        else{
            nurseList[i].showEmployeeInfo();
        }
    }
}

Team::~Team(){
    delete teamLeader;
    delete[] adminList;
    delete[] doctorList;
    delete[] nurseList;
}