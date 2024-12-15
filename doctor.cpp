#include "doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

Doctor::Doctor()
{
    base_salary = 0.0;
    bonus = 0.0;
    doctor_id = 0;
    dfirst_name = "";
    dlast_name = "";
    specialty = "";
    years_of_experience = 0;
}

// getters

std::string Doctor::getDocFName() {
    return dfirst_name;
}

std::string Doctor::getDocLName() {
    return dlast_name;
}

std::string Doctor::getSpecialty() {
    return specialty;
}

long int Doctor::getId() {
    return doctor_id;
}

double Doctor::getBSalary() {
    return base_salary;
}

int Doctor::getExperience() {
    return years_of_experience;
}

double Doctor::getBonus() {
    return bonus;
}


// setters
void Doctor::setDocFName(std::string dFname) {
    dfirst_name = dFname;
}

void Doctor::setDocLName(std::string dLname) {
    dlast_name = dLname;
}

void Doctor::setSpecialty(std::string specialty) {
    specialty = specialty;
}

void Doctor::setId(long int docID) {
     doctor_id = docID;
}

void Doctor::setBSalary(double baseSalary) {
     base_salary = baseSalary;
}

void Doctor::setExperience(int experience) {
     years_of_experience = experience;
}

void Doctor::setBonus(double bonus) {
     bonus = bonus;
}


// methods
double Doctor::calculate_salary() {//let me know tho 
    return base_salary + (bonus * base_salary); // this only returns a number, if we want it to print then we can change the function
}

void Doctor::print_Doctor_info() {
    std::cout << "Doctor Information:" << std::endl;
    std::cout << "First Name: " << dfirst_name << std::endl;
    std::cout << "Last Name: " << dlast_name << std::endl;
    std::cout << "Doctor ID: " << doctor_id << std::endl;
    std::cout << "Specialty: " << specialty << std::endl;
    std::cout << "Years of Experience: " << years_of_experience << std::endl;
    std::cout << "Base Salary: " << base_salary << std::endl;
    std::cout << "Performance Bonus: " << std::fixed << std::setprecision(2) << bonus * 100 << "%" << std::endl;
    std::cout << "Calculated Salary: " << calculate_salary() << std::endl;
}

