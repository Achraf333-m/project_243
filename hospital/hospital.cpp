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
    int i{0};
    int j{0};

    // opening and reading patients.txt
    try
    {
        patient_data.open("patients.txt", std::ios::in);
        if (patient_data.is_open())
        {
            while (std::getline(patient_data, line)) {
                // ignoring the number at the top of the page and the empty lines
                if (line.empty() || line.size() < 5) {
                    continue;
                }
                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 1);
                switch(i) {
                    case 0:
                        patient_ptr->at(j).setFName(data_substr);
                        break;
                    case 1:
                        patient_ptr->at(j).setLName(data_substr);
                        break;
                    case 2:
                        patient_ptr->at(j).setPatientID(std::stoi(data_substr));
                        break;
                    case 3:
                        patient_ptr->at(j).setAssignedDoctorID(std::stoi(data_substr));
                        break;
                    case 4:
                        patient_ptr->at(j).setDateOfBirth(data_substr);
                        break;
                    case 5:
                        patient_ptr->at(j).setBloodType(data_substr);
                        break;
                    case 6:
                        patient_ptr->at(j).setDiagnosis(data_substr);
                        break;
                    case 7:
                        patient_ptr->at(j).setDateOfAdmission(data_substr);
                        break;
                    case 8:
                        patient_ptr->at(j).setDischargeDate(data_substr);
                        break;
                }
                // incrementing i to go over methods
                i++;
                // once i reaches 9 (the empty space between each patient), it resets to 0 and increments j
                // i.e moves to the next object in the vector.
                if (i % 10 == 0) {
                    i = 0;
                    j++;
                }
                
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

    patient_data.close();
    line.clear();
    j = 0;
    i = 0;
    try
    {
        doctor_data.open("doctors.txt", std::ios::in);
        if (doctor_data.is_open())
        {
            while (std::getline(doctor_data, line)) {
                // ignoring the number at the top of the page and the empty lines
                if (line.empty() || line.size() < 5) {
                    continue;
                }
                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 1);
                switch(i) {
                    case 0:
                        doctor_ptr->at(j).setDocFName(data_substr);
                        break;
                    case 1:
                        doctor_ptr->at(j).setDocLName(data_substr);
                        break;
                    case 2:
                        doctor_ptr->at(j).setId(std::stoi(data_substr));
                        break;
                    case 3:
                        doctor_ptr->at(j).setSpecialty(data_substr);
                        break;
                    case 4:
                        doctor_ptr->at(j).setExperience(std::stoi(data_substr));
                        break;
                    case 5:
                        doctor_ptr->at(j).setBSalary(std::stoi(data_substr));
                        break;
                    case 6:
                        doctor_ptr->at(j).setBonus(std::stod(data_substr));
                        break;
                }
                // incrementing i to go over methods
                i++;
                // once i reaches 7 (the empty space between each patient after 7 data values), it resets to 0 and increments j
                // i.e moves to the next object in the vector.
                if (i == 7) {
                    i = 0;
                    j++;
                }
                
            }
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
    long int oldest{0};
    int oldest_patient_index{0};
    for (int i = 0; i < patient_ptr->size(); i++)
    {
        int visit_duration = 20240101 - std::stoi(patient_ptr->at(i).getDateOfAdmission());
        if (visit_duration > oldest)
        {
            oldest = visit_duration;
            oldest_patient_index = i;
        }
    }

    std::cout << "The oldest patient found is: \n"
              << "First name: " << patient_ptr->at(oldest_patient_index).getFName() << std::endl
              << "Last name: " << patient_ptr->at(oldest_patient_index).getLName() << std::endl
              << "Patient ID: " << patient_ptr->at(oldest_patient_index).getPatientID() << std::endl
              << "Date of birth: " << patient_ptr->at(oldest_patient_index).getDateOfBirth() << std::endl
              << "Blood type: " << patient_ptr->at(oldest_patient_index).getBloodType() << std::endl
              << "Admission date: " << patient_ptr->at(oldest_patient_index).getDateOfAdmission() << std::endl
              << "Discharge date: " << patient_ptr->at(oldest_patient_index).getDischargeDate() << std::endl
              << "Diagnosis: " << patient_ptr->at(oldest_patient_index).getDiagnosis() << std::endl
              << "Assigned doctor: " << patient_ptr->at(oldest_patient_index).getAssignedDoctorID() << std::endl;
}

int Hospital::count_critical_patients()
{
    int counter{0};
    for (int i = 0; i < patient_ptr->size(); i++)
    {
        if (patient_ptr->at(i).patient_status() == "critical")
        {
            counter++;
        }
    }

    return counter;
}

void Hospital::doctors_by_specialty(std::string specialty)
{
    if (!doctor_ptr->empty())
    {

        for (int i = 0; i < doctor_ptr->size(); i++)
        {
            if (doctor_ptr->at(i).getSpecialty() == specialty)
            {
                doctor_ptr->at(i).print_Doctor_info();
            }
        }
    }
    else
    {
        std::cout << "No doctor has the mentioned specialty." << std::endl;
    }
}

void Hospital::show_patient_by_id(long int id)
{
    bool found = false;
    try
    {
        for (int i = 0; i < patient_ptr->size(); i++)
        {
            if (patient_ptr->at(i).getPatientID() == id)
            {
                patient_ptr->at(i).print_Patient_info();
                found = true;
            }
        }
        if (!found)
        {
            throw "No patient has the provided ID.";
        }
    }
    catch (std::string message)
    {
        std::cout << message << std::endl;
    }
}

void Hospital::show_doctor_by_id(long int id)
{
    bool found = false;
    try
    {
        for (int i = 0; i < doctor_ptr->size(); i++)
        {
            if (doctor_ptr->at(i).getId() == id)
            {
                doctor_ptr->at(i).print_Doctor_info();
                found = true;
            }
        }
        if (!found)
        {
            throw "No doctor has the provided ID.";
        }
    }
    catch (std::string message)
    {
        std::cout << message << std::endl;
    }
}

void Hospital::show_assigned_doctor(long int id)
{
    long int doctor_id;
    bool found = false;
    for (int i = 0; i < patient_ptr->size(); i++)
    {
        if (patient_ptr->at(i).getPatientID() == id)
        {
            doctor_id = patient_ptr->at(i).getAssignedDoctorID();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "User not found." << std::endl;
    }
    else if (doctor_id == -1)
    {
        std::cout << "The patient has no assigned doctor." << std::endl;
    }
    else
    {
        found ? std::cout << "The assigned doctor for this patient is: " : std::cout << "";
        for (int i = 0; i < doctor_ptr->size(); i++)
        {
            if (doctor_ptr->at(i).getId() == doctor_id)
            {
                doctor_ptr->at(i).print_Doctor_info();
            }
        }
    }
}

void Hospital::show_assigned_patients(long int id)
{
    int count{0};
    for (int i = 0; i < patient_ptr->size(); i++) {
        if (patient_ptr->at(i).getAssignedDoctorID() == id) {
            patient_ptr->at(i).print_Patient_info();
            std::cout << std::endl;
            count++;
        }
    }
    if (!count) {
        std::cout << "No patients assigned." << std::endl;
    }
}