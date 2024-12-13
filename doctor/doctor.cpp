#include "doctor.h"
#include <iostream>
#include <string>

Doctor::Doctor()
{
    base_salary = 0.0;
    bonus = 0.0;
    doctor_id = 0;
    first_name = "";
    last_name = "";
    specialty = "";
    years_of_experience = 0;
}

// getters

std::string Doctor::getFName() {
    return first_name;
}

std::string Doctor::getLName() {
    return last_name;
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

// same thing goes for this, we need to discuss how we should be
// setting the needed info
void Doctor::setFName() {
    first_name;
}

void Doctor::setLName() {
    last_name;
}

void Doctor::setSpecialty() {
    specialty;
}

void Doctor::setId() {
     doctor_id;
}

void Doctor::setBSalary() {
     base_salary;
}

void Doctor::setExperience() {
     years_of_experience;
}

void Doctor::setBonus() {
     bonus;
}


// methods

double Doctor::calculate_salary() {
    // logic 
    return base_salary * bonus + base_salary;
}

void Doctor::print_Doctor_info() {
    // logic here
}