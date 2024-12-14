#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "patient\patient.h"
#include "doctor\doctor.h"
#include <vector>

class Hospital
{
private:
    std::vector<Patient>* &patient_ptr;
    std::vector<Doctor>* &doctor_ptr;

public:
    Hospital();

    // members
    void find_oldest_patient();
    int count_critical_patients();
    void doctors_by_specialty(std::string specialty);
    void show_patient_by_id(long int id);
    void show_doctor_by_id(long int id);
    void show_assigned_doctor(long int id);
    void show_assigned_patients(long int id);
};

#endif