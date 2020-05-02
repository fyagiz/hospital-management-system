#include <iostream>
#include <cstring>
#include "employee.h"
#include "doctor.h"
#include "nurse.h"
#include "admin.h"
#include "team.h"
#include "hospital.h"

/*
                                                            Furkan Yagiz 2152197
                                                    CNG 242 Programming Language Concepts
                                                Assignment 2 (C++): Hospital Management System
*/

// Auxiliary Function Prototypes
void menu(); // This function operates menu.
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

int main(){

    menu();

    return 0;
}

// This function operates menu.
void menu(){
    char command;
    Hospital *hospital = new Hospital;

    std::cout << "Welcome to Hospital Management System!" << std::endl;

    do{
        std::cout << "1. Create a team" << std::endl;
        std::cout << "2. Search a member by ID" << std::endl;
        std::cout << "3. List all members" << std::endl;
        std::cout << "4. List total annual salary" << std::endl;
        std::cout << "5. List all members of a given team" << std::endl;
        std::cout << "6. List total annual salary of a given team" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your selection: ";
        std::cin >> command;

        switch(command){
            
            case '1':
                createTeamMenu(hospital);
                break;
            case '2':
                searchMemberByIDMenu(hospital);
                break;
            case '3':
                listAllMembersMenu(hospital);
                break;
            case '4':
                listTotalAnnualSalaryMenu(hospital);
                break;
            case '5':
                listAllMembersOfGivenTeamMenu(hospital);
                break;
            case '6':
                listTotalAnnualSalaryOfGivenTeam(hospital);
                break;
            case '7':
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Wrong options! Please try again." << std::endl;
                break;

        };

    }while (command != '7');
}

// This function operates Create Team Menu
void createTeamMenu(Hospital *hospital){

    int integer_input;
    int teamID;
    char *char_input = new char[100];

    Doctor *tmpLeader = new Doctor();

    

    std::cout << "Team ID: ";
    std::cin >> teamID;
    hospital->addNewTeam(teamID);

    

    std::cout << "Enter the details of the team leader: " << std::endl;
    getEmployeeInfo(tmpLeader);
    

    std::cout << "Doctor Type: (3) SPECIALIST (4) DOCENT (5) PROFESSOR: ";
    std::cin >> integer_input;

    switch (integer_input){
        case 3:
            tmpLeader->setTitle(Specialist);
            break;
        case 4:
            tmpLeader->setTitle(Docent);
            break;
        case 5:
            tmpLeader->setTitle(Professor);
            break;
        default:
            std::cout << "Wrong type entered. Doctor Type is setted Professor!" << std::endl;
            tmpLeader->setTitle(Professor);
            break;
    }

    hospital->getTeamByID(teamID)->setTeamLeader(tmpLeader);

    std::cout << "The team leader has been added to the team successfully!" << std::endl;

    char mod;
    while(true){
        std::cout << "Would you like to add a new member to your team (Y/N): ";

        std::fflush(stdin);
        std::cin >> mod;

        if (mod == 'Y' || mod == 'y'){
            std::cout << "1. Doctor" << std::endl;
            std::cout << "2. Nurse" << std::endl;
            std::cout << "3. Admin" << std::endl;
            std::cout << "Select type: ";
            std::cin >> integer_input;
            std::cout << "Enter the details of the team member: " << std::endl;
            
            switch(integer_input){
                case 1:
                    addNewDoctor(hospital->getTeamByID(teamID));
                    break;
                case 2:
                    addNewNurse(hospital->getTeamByID(teamID));
                    break;
                case 3:
                    addNewAdmin(hospital->getTeamByID(teamID));
                    break;
            }
        }

        else
            break;
        
    }

    std::cout << "The team has been added to the hospital successfully!" << std::endl;
}

// This function operates Search Member By ID Menu
void searchMemberByIDMenu(Hospital *hospital){
    int i;
    bool flag = false;
    int integer_input;
    std::cout << "Enter member ID: ";
    std::cin >> integer_input;

    Team *tmpTeams = hospital->getTeams();

    for(i=0;i<100;i++){
        if(tmpTeams[i].getTeamID() == -1)
            break;
        else{
            if(tmpTeams[i].searchEmployeeByEmployeeID(integer_input)){
                flag = true;
                break;
            }
            else
                continue; 
        }
    }

    if (flag == false){
        std::cout << "The employee was not found! Employee ID: " << integer_input << std::endl;
    }

}

// This function operates listing all members menu.
void listAllMembersMenu(Hospital *hospital){
    int i;
    Team *tmpTeams = hospital->getTeams();

    for(i=0;i<100;i++){
        if (tmpTeams[i].getTeamID() != -1)
            tmpTeams[i].listLeaderAndMembers();
        else
            break;
    }
}

// This function operates listing total annual salary menu.
void listTotalAnnualSalaryMenu(Hospital *hospital){

    std::cout << "Total annual salary is " << hospital->totalAnnualSalary() << std::endl;

}

// This function operates listing all members of a given team menu.
void listAllMembersOfGivenTeamMenu(Hospital *hospital){
    int integer_input;
    std::cout << "Enter team ID: ";
    std::cin >> integer_input;

    hospital->getTeamByID(integer_input)->listLeaderAndMembers();
}

// This function operates listing total annual salary of a given team menu.
void listTotalAnnualSalaryOfGivenTeam(Hospital *hospital){
    int integer_input;
    std::cout << "Enter team ID: ";
    std::cin >> integer_input;

    std::cout << "Total annual salary for Team " << integer_input << " is " << hospital->getTeamByID(integer_input)->teamAnnualCostCalculator() << std::endl;
}

// This function takes employee information from user.
void getEmployeeInfo(Employee *tmpEmployee){

    int integer_input;
    char *char_input = new char[100];

    std::cout << "ID: ";
    std::cin >> integer_input;
    tmpEmployee->setEmployeeID(integer_input);

    std::cout << "First Name: ";
    std::cin >> char_input;
    tmpEmployee->setFirstName(char_input);

    std::cout << "Last Name: ";
    std::fflush(stdin);
    std::cin >> char_input;
    tmpEmployee->setLastName(char_input);

    std::cout << "Telephone number: ";
    std::cin >> integer_input;
    tmpEmployee->setTelephoneNumber(integer_input);

    std::cout << "Address: ";
    std::fflush(stdin);
    std::cin.getline(char_input, 100);
    tmpEmployee->setAddress(char_input);

    std::cout << "Email: ";
    std::fflush(stdin);
    std::cin >> char_input;
    tmpEmployee->setEmail(char_input);

    std::cout << "Salary: ";
    std::cin >> integer_input;
    tmpEmployee->setAnnualSalary(integer_input);
}

// This function adds new doctor into the team.
void addNewDoctor(Team *tmpTeam){

    int integer_input;
    char *char_input = new char[100];
    Doctor *tmpDoctor = new Doctor();


    std::cout << "ID: ";
    std::cin >> integer_input;
    tmpDoctor->setEmployeeID(integer_input);

    std::cout << "First Name: ";
    std::cin >> char_input;
    tmpDoctor->setFirstName(char_input);

    std::cout << "Last Name: ";
    std::fflush(stdin);
    std::cin >> char_input;
    tmpDoctor->setLastName(char_input);

    std::cout << "Telephone number: ";
    std::cin >> integer_input;
    tmpDoctor->setTelephoneNumber(integer_input);

    std::cout << "Address: ";
    std::fflush(stdin);
    std::cin.getline(char_input, 100);
    tmpDoctor->setAddress(char_input);

    std::cout << "Email: ";
    std::fflush(stdin);
    std::cin >> char_input;
    tmpDoctor->setEmail(char_input);

    std::cout << "Salary: ";
    std::cin >> integer_input;
    tmpDoctor->setAnnualSalary(integer_input);

    
    std::cout << "Doctor Type: (0) Intern (1) Practitioner (2) Assistant: ";
    std::cin >> integer_input;

    switch (integer_input){
        case 0:
            tmpDoctor->setTitle(Intern);
            break;
        case 1:
            tmpDoctor->setTitle(Practitioner);
            break;
        case 2:
            tmpDoctor->setTitle(Assistant);
            break;
        default:
            std::cout << "Wrong type entered. Doctor Type is setted Intern!" << std::endl;
            tmpDoctor->setTitle(Intern);
            break;
    }

    tmpTeam->addDoctorToTeam(tmpDoctor);
}

// This function adds new nurse into the team.
void addNewNurse(Team *tmpTeam){

    int integer_input;
    char *char_input = new char[100];
    Nurse *tmpNurse = new Nurse();

    getEmployeeInfo(tmpNurse);

    std::cout << "Nurse Type: (0) GENERAL (1) MIDWIFE  ";
    std::cin >> integer_input;

    switch (integer_input){
        case 0:
            tmpNurse->setTitle(General);
            break;
        case 1:
            tmpNurse->setTitle(Midwife);
            break;
        default:
            std::cout << "Wrong type entered. Nurse Type is setted General!" << std::endl;
            tmpNurse->setTitle(General);
            break;
    }
    
    std::cout << "Hours over time Per Week: ";
    std::cin >> integer_input;

    tmpNurse->overtimeAnnualSalaryCalculate(integer_input);

    tmpTeam->addNurseToTeam(tmpNurse);
}

// This function adds new admin into the team.
void addNewAdmin(Team *tmpTeam){

    int integer_input;
    char *char_input = new char[100];
    Admin *tmpAdmin = new Admin();

    getEmployeeInfo(tmpAdmin);

    std::cout << "Admin Type: (0) Manager (1) Secretary";
    std::cin >> integer_input;

    switch (integer_input){
        case 0:
            tmpAdmin->setType(Manager);
            break;
        case 1:
            tmpAdmin->setType(Secretary);
            break;
        default:
            std::cout << "Wrong type entered. aDMİN Type is setted Secretary!" << std::endl;
            tmpAdmin->setType(Secretary);
            break;
    }

    std::cout << "Hours over time Per Week: ";
    std::cin >> integer_input;

    tmpAdmin->overTimeSalaryCalculator(integer_input);

    tmpTeam->addAdminToTeam(tmpAdmin);
}