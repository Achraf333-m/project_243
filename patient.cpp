#include "patient.h"
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

std::string Patient::getDateOfAdmission() {
    return date_of_admission;
}
std::string Patient::getDateOfBirth() {
    return date_of_birth;
}
std::string Patient::getBloodType() {
    return blood_type;
}
std::string Patient::getDiagnosis() {
    return diagnosis;
}
std::string Patient::getDischargeDate() {
    return discharge_date;
}
std::string Patient::getFName() {
    return first_name;
}
std::string Patient::getLName() {
    return last_name;
}
long int Patient::getPatientID() {
    return patient_id;
}
long int Patient::getAssignedDoctorID() {
    return assigned_doctor;
}


// setters
void Patient::setFName(std::string fname) {
    first_name = fname;
}
void Patient::setLName(std::string lname) {
    last_name = lname;
}
void Patient::setPatientID(long int id){
    patient_id = id;
}
void Patient::setAssignedDoctorID(long int doctorID){
    assigned_doctor = doctorID;
}
void Patient::setDateOfBirth(std::string dob) {
    date_of_birth = dob;
}
void Patient::setBloodType(std::string bType) {
    blood_type = bType;
}
void Patient::setDiagnosis(std::string diag) {
    diagnosis = diag;
}
void Patient::setDischargeDate(std::string doa) {
    discharge_date = doa;
}
void Patient::setDateOfAdmission(std::string dDate) {
    date_of_admission = dDate;
}


// methods

std::string Patient::patient_status() {
     if (diagnosis.find_first_of("critical_") != std::string::npos) {
        return "Critical";
    } 
    else if (diagnosis.find_first_of("moderate_") != std::string::npos) {
        return "Moderate";
    } 
    else {
        return "Stable";
    }
}

void Patient::print_Patient_info()
{
std::cout << "Patient Information:" << std::endl;
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Patient ID: " << patient_id << std::endl;
    std::cout << "Assigned Doctor ID: " << (assigned_doctor == -1 ? "None" : std::to_string(assigned_doctor)) << std::endl;
    std::cout << "Date of Birth: " << date_of_birth << std::endl;
    std::cout << "Blood Type: " << blood_type << std::endl;
    std::cout << "Diagnosis: " << diagnosis << std::endl;
    std::cout << "Date of Admission: " << date_of_admission << std::endl;
    std::cout << "Discharge Date: " << (discharge_date.empty() ? "Not Discharged" : discharge_date) << std::endl;
    std::cout << "Status: " << patient_status() << std::endl;


}

  

