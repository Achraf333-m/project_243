#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "patient\patient.h"
#include "doctor\doctor.h"
#include <vector>

class Hospital
{
private:
    std::vector<Patient> patient_v;
    std::vector<Doctor> doctor_v;

    Patient *patient_ptr = &patient_v[0];
    Doctor *doctor_ptr = &doctor_v[0];

public:
    Hospital();
};

#endif