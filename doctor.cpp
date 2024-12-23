#include "doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

Doctor::Doctor()
{
    base_salary = 0.0;
    doc_bonus = 0.0;
    doctor_id = 0;
    dfirst_name = "";
    dlast_name = "";
    doc_specialty = "";
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
    return doc_specialty;
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
    return doc_bonus;
}


// setters
void Doctor::setDocFName(std::string dFname) {
    dfirst_name = dFname;
}

void Doctor::setDocLName(std::string dLname) {
    dlast_name = dLname;
}

void Doctor::setSpecialty(std::string specialty) {
    doc_specialty = specialty;
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
     doc_bonus = bonus;
}


// methods
double Doctor::calculate_salary() {
    return base_salary + (doc_bonus * base_salary);
}

void Doctor::print_Doctor_info() {
    std::cout << "\nDoctor Information:" << std::endl;
    std::cout << "First Name: " << dfirst_name << std::endl;
    std::cout << "Last Name: " << dlast_name << std::endl;
    std::cout << "Doctor ID: " << doctor_id << std::endl;
    std::cout << "Specialty: " << doc_specialty << std::endl;
    std::cout << "Years of Experience: " << years_of_experience << std::endl;
    std::cout << "Base Salary: " << base_salary << std::endl;
    std::cout << "Performance doc: " << std::fixed << std::setprecision(2) << doc_bonus * 100.00 << "%" << std::endl;
    std::cout << "Calculated Salary: " << calculate_salary() << std::endl;
}

