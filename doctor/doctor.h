#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
    private:
        std::string first_name, last_name, specialty;
        long int doctor_id;
        int years_of_experience;
        double base_salary;
        double bonus;
    public:
    Doctor();

    // getters
    std::string getFName();
    std::string getLName();
    std::string getSpecialty();
    long int getId();
    int getExperience();
    double getBSalary();
    double getBonus();

    // setters
    void setFName();
    void setLName();
    void setSpecialty();
    void setId();
    void setExperience();
    void setBSalary();
    void setBonus();

    // methods
    double calculate_salary();
    void print_Doctor_info();

};

#endif