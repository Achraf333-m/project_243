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
    int i{0};

    // opening and reading patients.txt
    try
    {
        patient_data.open("patients.txt", std::ios::in);
        if (patient_data.is_open())
        {
            while (i == 0)
            {
                // getting the number at the first line as size
                std::getline(patient_data, line);
                i++;
            }
            size = std::stoi(line);
            patientptr = new Patient[size];
            i = 0;

            while (std::getline(patient_data, line))
            {
                // ignoring the number at the top of the page and the empty lines
                if (line.empty())
                {
                    continue;
                }
                else if (!line.empty() && line.size() < 5)
                {
                    size = std::stoi(line);
                }

                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 1);
                switch (i)
                {
                case 0:
                    patientptr->setFName(data_substr);
                    // patient_ptr->at(j).setFName(data_substr);
                    break;
                case 1:
                    patientptr->setLName(data_substr);
                    // patient_ptr->at(j).setLName(data_substr);
                    break;
                case 2:
                    patientptr->setPatientID(std::stoi(data_substr));
                    // patient_ptr->at(j).setPatientID(std::stoi(data_substr));
                    break;
                case 3:
                    patientptr->setAssignedDoctorID(std::stoi(data_substr));
                    // patient_ptr->at(j).setAssignedDoctorID(std::stoi(data_substr));
                    break;
                case 4:
                    patientptr->setDateOfBirth(data_substr);
                    // patient_ptr->at(j).setDateOfBirth(data_substr);
                    break;
                case 5:
                    patientptr->setBloodType(data_substr);
                    // patient_ptr->at(j).setBloodType(data_substr);
                    break;
                case 6:
                    patientptr->setDiagnosis(data_substr);
                    // patient_ptr->at(j).setDiagnosis(data_substr);
                    break;
                case 7:
                    patientptr->setDateOfAdmission(data_substr);
                    // patient_ptr->at(j).setDateOfAdmission(data_substr);
                    break;
                case 8:
                    patientptr->setDischargeDate(data_substr);
                    // patient_ptr->at(j).setDischargeDate(data_substr);
                    break;
                }
                // incrementing i to go over methods
                i++;
                // once i reaches 9 (the empty space between each patient), it resets to 0 and increments j
                // i.e moves to the next object in the vector.
                if (i % 10 == 0)
                {
                    i = 0;
                    patientptr++;
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
    i = 0;
    try
    {
        doctor_data.open("doctors.txt", std::ios::in);
        if (doctor_data.is_open())
        {
            while (i == 0)
            {
                // getting the number at the first line as size
                std::getline(doctor_data, line);
                i++;
            }
            size = std::stoi(line);
            doctorptr = new Doctor[size];
            i = 0;
            while (std::getline(doctor_data, line))
            {
                // ignoring the number at the top of the page and the empty lines
                if (line.empty() || line.size() < 5)
                {
                    continue;
                }
                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 1);
                switch (i)
                {
                case 0:
                    doctorptr->setDocFName(data_substr);
                    // doctor_ptr->at(j).setDocFName(data_substr);
                    break;
                case 1:
                    doctorptr->setDocLName(data_substr);
                    // doctor_ptr->at(j).setDocLName(data_substr);
                    break;
                case 2:
                    doctorptr->setId(std::stoi(data_substr));
                    // doctor_ptr->at(j).setId(std::stoi(data_substr));
                    break;
                case 3:
                    doctorptr->setSpecialty(data_substr);
                    // doctor_ptr->at(j).setSpecialty(data_substr);
                    break;
                case 4:
                    doctorptr->setExperience(std::stoi(data_substr));
                    // doctor_ptr->at(j).setExperience(std::stoi(data_substr));
                    break;
                case 5:
                    doctorptr->setBSalary(std::stoi(data_substr));
                    // doctor_ptr->at(j).setBSalary(std::stoi(data_substr));
                    break;
                case 6:
                    doctorptr->setBonus(std::stod(data_substr));
                    // doctor_ptr->at(j).setBonus(std::stod(data_substr));
                    break;
                }
                // incrementing i to go over methods
                i++;
                // once i reaches 7 (the empty space between each patient after 7 data values), it resets to 0 and increments j
                // i.e moves to the next object in the vector.
                if (i == 7)
                {
                    i = 0;
                    doctorptr++;
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

    size_p = sizeof(patientptr)/sizeof(patientptr[0]);
    size_d = sizeof(doctorptr)/sizeof(doctorptr[0]);

}

void Hospital::find_oldest_patient()
{
    long int oldest{0};
    int count;
    std::string dateofadmission;
    
    while (count < size_p)
    {
        int visit_duration = 20240101 - std::stoi(patientptr->getDateOfAdmission());
        if (visit_duration > oldest)
        {
            oldest = visit_duration;
            dateofadmission = patientptr->getDateOfAdmission();
            
        }
        count++;
        patientptr++;
    }

    while (size_p--) {
        if (dateofadmission == patientptr->getDateOfAdmission()) {
            patientptr->print_Patient_info();
            break;
        }
        patientptr++;
    }
}

int Hospital::count_critical_patients()
{
    int counter{0};
    for (int i = 0; i < size_p; i++)
    {
        if (patientptr->patient_status() == "critical")
        {
            counter++;
        }
        patientptr++;
    }

    return counter;
}

void Hospital::doctors_by_specialty(std::string specialty)
{
    bool found = false;
    if (size_d)
    {
        try {
        for (int i = 0; i < size_d; i++)
        {
            if (doctorptr->getSpecialty() == specialty)
            {
                doctorptr->print_Doctor_info();
                found = true;
            }
            doctorptr++;
        }
        if (!found) {
            throw "No doctor has the mentioned specialty.";
        }

        } catch (std::string m) {
            std::cout << m << std::endl;
        }

    }
    else
    {
        std::cout << "The doctors' data is inaccessible." << std::endl;
    }
}

void Hospital::show_patient_by_id(long int id)
{
    bool found = false;
    try
    {
        for (int i = 0; i < size_p; i++)
        {
            if (patientptr->getPatientID() == id)
            {
                patientptr->print_Patient_info();
                found = true;
            }
            patientptr++;
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
        for (int i = 0; i < size_d; i++)
        {
            if (doctorptr->getId() == id)
            {
                doctorptr->print_Doctor_info();
                found = true;
            }
            doctorptr++;
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
    for (int i = 0; i < size_p; i++)
    {
        if (patientptr->getPatientID() == id)
        {
            doctor_id = patientptr->getAssignedDoctorID();
            found = true;
        }
        patientptr++;
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
        for (int i = 0; i < size_d; i++)
        {
            if (doctorptr->getId() == doctor_id)
            {
                doctorptr->print_Doctor_info();
            }
            doctorptr++;
        }
    }
}

void Hospital::show_assigned_patients(long int id)
{
    int count{0};
    for (int i = 0; i < size_p; i++)
    {
        if (patientptr->getAssignedDoctorID() == id)
        {
            patientptr->print_Patient_info();
            std::cout << std::endl;
            count++;
        }
        patientptr++;
    }
    if (!count)
    {
        std::cout << "No patients assigned." << std::endl;
    }
}