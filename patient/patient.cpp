#include "patient.h";
#include <iostream>
#include <string>


Patient::Patient() {
    assigned_doctor = 0;
    blood_type = "";
    date_of_admission = "";
    date_of_birth = "";
    diagnosis = "";
    discharge_date = "";
    first_name = "";
    last_name = "";
    patient_id = 0;
}


// getters

std::string Patient::getAdmission() {
    return date_of_admission;
}
std::string Patient::getBirth() {
    return date_of_birth;
}
std::string Patient::getBlood() {
    return blood_type;
}
std::string Patient::getDiagnosis() {
    return diagnosis;
}
std::string Patient::getDischarge() {
    return discharge_date;
}
std::string Patient::getFName() {
    return first_name;
}
std::string Patient::getLName() {
    return last_name;
}


// setters


// in here, we will have to see whether we should prompt the user
// for data and if we are going to write it directly into the patients.txt file
void Patient::setAdmission() {
    date_of_admission;
}
void Patient::setBirth() {
    date_of_birth;
}
void Patient::setBlood() {
    blood_type;
}
void Patient::setDiagnosis() {
    diagnosis;
}
void Patient::setDischarge() {
    discharge_date;
}
void Patient::setFName() {
    first_name;
}
void Patient::setLName() {
    last_name;
}



// methods

std::string Patient::patient_status() {
    // logic
    return "stable";
}
