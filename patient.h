#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
private:
    std::string first_name, last_name, date_of_birth, blood_type, diagnosis, discharge_date, date_of_admission;
    long int patient_id, assigned_doctor;
public:
    //constructor
    Patient();

    // getters
    std::string getFName();
    std::string getLName();
    long int getPatientID();
    long int getAssignedDoctorID();
    std::string getDateOfBirth();
    std::string getBloodType();
    std::string getDiagnosis();
    std::string getDischargeDate();
    std::string getDateOfAdmission();
    
    // setters
    void setFName(std::string fname);
    void setLName(std::string lname);
    void setPatientID(long int id);
    void setAssignedDoctorID(long int doctorID);
    void setDateOfBirth(std::string dob);
    void setBloodType(std::string bType);
    void setDiagnosis(std::string diag);
    void setDischargeDate(std::string doa);
    void setDateOfAdmission(std::string dDate);
    
    // methods
    std::string patient_status();
    void print_Patient_info();

};

#endif