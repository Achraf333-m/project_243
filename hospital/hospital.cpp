#include "hospital.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Hospital::Hospital()
{
    std::fstream patient_data;
    std::fstream doctor_data;
    std::string line;
    int size{0};

    // opening and reading patients.txt
    try
    {
        patient_data.open("patients.txt", std::ios::in);
        if (patient_data.is_open())
        {
            while (patient_data)
            {
                size++;
            }

            while (patient_data)
            {
                std::getline(patient_data, line);
                size++;
            }
        }
        else
        {
            throw "Patient data is inaccessible!";
        }
    }
    catch (std::string m)
    {
        std::cout << m;
    }

    try
    {
        doctor_data.open("doctors.txt", std::ios::in);
        if (doctor_data.is_open())
        {
            // something here
        }
        else
        {
            throw "Doctor data is inaccessible!";
        }
    }
    catch (std::string m)
    {
        std::cout << m;
    }
}

void Hospital::find_oldest_patient()
{
    // iterate through the array of patients
    // compare (20240101 - date of admission) and set it to variable oldest
    // every iteration then print detail of patient[i]
}

int Hospital::count_critical_patients()
{
    // find every patient where status is critical and increment a counter
    // return counter
}

void Hospital::doctors_by_specialty(std::string specialty)
{
    // if doctor in doctor array has specialty = specialty, print.
}

void Hospital::show_patient_by_id(long int id)
{
    // if patient in patients list has id == id
    // print patient
}

void Hospital::show_doctor_by_id(long int id)
{
    // if doctor in doctors list has id == id
    // print doctor
}

void Hospital::show_assigned_doctor(long int id)
{
    // if patient in patient list has id == id then
    // cout assigned doctor, similar id to doctor in doctors list then print doctor
}

void Hospital::show_assigned_patients(long int id)
{
    // iterate through patients, if id == assigned doctor id, push to a vector
    // iterate over that vector to show patients
}