#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "patient.h"
#include "doctor.h"
#include <vector>

class Hospital
{
private:
    Patient *patientptr;
    Doctor *doctorptr;
    int size_p{0};
    int size_d{0};
    // WHAT ARE THESE FOR ???
    std::vector<Patient>* patient_ptr;
    std::vector<Doctor>* doctor_ptr;

public:
    Hospital();
    ~Hospital();

    //maybe we can use these to load in the data from the files and then operate on the data (this will load it into the vectors)
    void loadPatients(const std::string& filename);
    void loadDoctors(const std::string& filename);
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