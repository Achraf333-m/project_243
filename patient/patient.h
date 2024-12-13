#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
private:
    std::string first_name, last_name, date_of_birth, blood_type, diagnosis, discharge_date, date_of_admission;
    long int patient_id, assigned_doctor;
public:
    Patient();

    // getters
    std::string getFName();
    std::string getLName();
    std::string getBirth();
    std::string getBlood();
    std::string getDiagnosis();
    std::string getDischarge();
    std::string getAdmission();
    
    // setters
    void setFName();
    void setLName();
    void setBirth();
    void setBlood();
    void setDiagnosis();
    void setDischarge();
    void setAdmission();
    
    // methods
    std::string patient_status();
   
};

#endif