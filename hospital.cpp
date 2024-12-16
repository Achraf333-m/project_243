#include "hospital.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Hospital::~Hospital(){
    delete[] doctorptr;
    delete[] patientptr;
}

Hospital::Hospital()
{
    std::fstream patient_data;
    std::fstream doctor_data;
    std::string line;
    int i{0};
    int index{0};
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
            size_p = std::stol(line);

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
                // if line is between objects, ignore it but reset i and move to the next object
                else if (line.find("*****") != -1)
                {
                    i = 0;
                    index++;
                    continue;
                }
                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 1);
                switch (i)
                {
                case 0:
                    patientptr[index].setFName(data_substr);

                    break;
                case 1:
                    patientptr[index].setLName(data_substr);

                    break;
                case 2:
                    patientptr[index].setPatientID(std::stol(data_substr));

                    break;
                case 3:
                    patientptr[index].setAssignedDoctorID(std::stol(data_substr));

                    break;
                case 4:
                    patientptr[index].setDateOfBirth(data_substr);

                    break;
                case 5:
                    patientptr[index].setBloodType(data_substr);

                    break;
                case 6:
                    patientptr[index].setDiagnosis(data_substr);

                    break;
                case 7:
                    patientptr[index].setDateOfAdmission(data_substr);

                    break;
                case 8:
                    patientptr[index].setDischargeDate(data_substr);

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
    index = 0;
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
            doctorptr = new Doctor[size_d];
            i = 0;
            line.clear();
            while (std::getline(doctor_data, line))
            {
                // ignoring the number at the top of the page and the empty lines
                if (i == 0 && line.empty())
                {
                    continue;
                }
                else if (line.size() < 3 ) {
                    continue;
                }
                
                else if (line.find("*****") != -1)
                {
                    i = 0;
                    index++;
                    continue;
                }
                int limit = line.find(":");
                // using only the value that comes after the colon.
                std::string data_substr = line.substr(limit + 2);
                switch (i)
                {
                case 0:
                    doctorptr[index].setDocFName(data_substr);

                    break;
                case 1:
                    doctorptr[index].setDocLName(data_substr);

                    break;
                case 2:
                    doctorptr[index].setId(std::stol(data_substr));

                    break;
                case 3:
                    doctorptr[index].setSpecialty(data_substr);

                    break;
                case 4:
                    doctorptr[index].setExperience(std::stol(data_substr));

                    break;
                case 5:
                    doctorptr[index].setBSalary(std::stol(data_substr));

                    break;
                case 6:

                    doctorptr[index].setBonus(std::stof(data_substr));

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
}

void Hospital::find_oldest_patient()
{
    long int oldest{0};
    int count{0};
    int index{0};
    std::string dateofadmission;

    while (count < size_p)
    {
        int visit_duration = 20240101 - std::stoi(patientptr[index].getDateOfAdmission());
        if (visit_duration > oldest)
        {
            oldest = visit_duration;
            dateofadmission = patientptr[index].getDateOfAdmission();
        }
        count++;
        index++;
    }

    index = 0;
    std::cout << std::endl << "The oldest patient's data is: \n" << std::endl;
    while (index < size_p)
    {
        if (dateofadmission == patientptr[index].getDateOfAdmission())
        {
            patientptr[index].print_Patient_info();
            break;
        }
        index++;
    }
}

int Hospital::count_critical_patients()
{
    int counter{0};
    int index{0};
    for (int i = 0; i < size_p; i++)
    {
        if (patientptr[index].patient_status() == "Critical")
        {
            counter++;
        }
        index++;
    }

    return counter;
}

void Hospital::doctors_by_specialty(std::string specialty)
{
    bool found = false;
    int index{0};
    if (size_d)
    {
        try
        {
            for (int i = 0; i < size_d; i++)
            {
                if (doctorptr[index].getSpecialty() == specialty)
                {
                    doctorptr[index].print_Doctor_info();
                    found = true;
                }
                index++;
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
    int index{0};
    try
    {
        for (int i = 0; i < size_p; i++)
        {
            if (patientptr[index].getPatientID() == id)
            {
                patientptr[index].print_Patient_info();
                found = true;
            }
            index++;
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
    int index{0};
    try
    {
        for (int i = 0; i < size_d; i++)
        {
            if (doctorptr[index].getId() == id)
            {
                doctorptr[index].print_Doctor_info();
                found = true;
            }
            index++;
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
    long int doctor_id{0};
    bool found = false;
    int index{0};
    for (int i = 0; i < size_p; i++)
    {
        if (patientptr[index].getPatientID() == id)
        {
            doctor_id = patientptr[index].getAssignedDoctorID();
            found = true;
        }
        index++;
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
        index = 0;
        found ? std::cout << "The assigned doctor for this patient is: \n\n" : std::cout << "";
        for (int i = 0; i < size_d; i++)
        {
            if (doctorptr[index].getId() == doctor_id)
            {
                doctorptr[index].print_Doctor_info();
                break;
            }
            index++;
        }
    }
}

void Hospital::show_assigned_patients(long int id)
{
    int count{0};
    int index{0};
    std::cout << "\nThe assigned patients for this doctor are: \n\n";
    for (int i = 0; i < size_p; i++)
    {
        if (patientptr[index].getAssignedDoctorID() == id)
        {
            patientptr[index].print_Patient_info();
            std::cout << std::endl;
            count++;
        }
        index++;
    }
    if (!count)
    {
        std::cout << "No patients assigned." << std::endl;
    }
}