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
    // int size{0};
    int i{0};
    int count{0};

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
            // this causes no problem
            size_p = std::stol(line);
            std::cout << size_p;

            patientptr = new Patient[size_p];
            i = 0;
            line.clear();

            while (std::getline(patient_data, line))
            {
                
                // ignoring the number at the top of the page and the empty lines
                if (i == 0 && line.empty())
                {
                    continue;
                }
                else if (line.size() < 3 ) {
                    continue;
                }
                else if (line.empty() && i > 0)
                {
                    std::cout << "done \n ";
                    i = 0;
                    patientptr++;
                    continue;
                }

                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 1);
                switch (i)
                {
                case 0:
                    patientptr->setFName(data_substr);

                    break;
                case 1:
                    patientptr->setLName(data_substr);

                    break;
                case 2:
                    std::cerr << "Debug: Converting " << data_substr << " at i " << i << " and " << patientptr->getFName() << " to int" << std::endl;
                    patientptr->setPatientID(std::stol(data_substr));

                    break;
                case 3:
                    patientptr->setAssignedDoctorID(std::stol(data_substr));

                    break;
                case 4:
                    patientptr->setDateOfBirth(data_substr);

                    break;
                case 5:
                    patientptr->setBloodType(data_substr);

                    break;
                case 6:
                    patientptr->setDiagnosis(data_substr);

                    break;
                case 7:
                    patientptr->setDateOfAdmission(data_substr);

                    break;
                case 8:
                    patientptr->setDischargeDate(data_substr);

                    break;
                }
                // incrementing i to go over methods
                i++;
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
            size_d = std::stol(line);
            std::cout << size_d;
            doctorptr = new Doctor[size_d];
            i = 0;
            line.clear();
            while (std::getline(doctor_data, line))
            {
                // ignoring the number at the top of the page and the empty lines
                if (line.size() < 3 || line.empty())
                {
                    continue;
                }
                else if (line.empty() && i > 0)
                {
                    i = 0;
                    doctorptr++;
                    continue;
                }
                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 2);
                switch (i)
                {
                case 0:
                    doctorptr->setDocFName(data_substr);

                    break;
                case 1:
                    doctorptr->setDocLName(data_substr);

                    break;
                case 2:
                    std::cerr << "Debug: Converting " << data_substr << " at i " << i << " and " << doctorptr->getDocFName() << " to int" << std::endl;
                    doctorptr->setId(std::stol(data_substr));

                    break;
                case 3:
                    doctorptr->setSpecialty(data_substr);

                    break;
                case 4:
                    doctorptr->setExperience(std::stol(data_substr));

                    break;
                case 5:
                    doctorptr->setBSalary(std::stol(data_substr));

                    break;
                case 6:
                    std::cerr << "Debug: getting bonus " << data_substr << " at i " << i << " and " << doctorptr->getDocFName() << " to float" << std::endl;

                    doctorptr->setBonus(std::stof(data_substr));

                    break;
                }
                // incrementing i to go over methods
                i++;

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

    std::cout << size_d << " " << size_p << std::endl;
}

void Hospital::find_oldest_patient()
{
    long int oldest{0};
    int count;
    std::string dateofadmission;

    std::cout << patientptr[0].getDiagnosis() << " and ";
    std::cout << doctorptr[0].getSpecialty();
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

    while (size_p--)
    {
        if (dateofadmission == patientptr->getDateOfAdmission())
        {
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
        try
        {
            for (int i = 0; i < size_d; i++)
            {
                if (doctorptr->getSpecialty() == specialty)
                {
                    doctorptr->print_Doctor_info();
                    found = true;
                }
                doctorptr++;
            }
            if (!found)
            {
                throw "No doctor has the mentioned specialty.";
            }
        }
        catch (std::string m)
        {
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
            throw std::runtime_error("No patient has the provided ID.");
        }
    }
    catch (std::runtime_error message)
    {
        std::cout << message.what() << std::endl;
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
            throw std::runtime_error("No doctor has the provided ID.");
        }
    }
    catch (std::runtime_error message)
    {
        std::cout << message.what() << std::endl;
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