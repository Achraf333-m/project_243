#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
    private:
        std::string dfirst_name, dlast_name, doc_specialty;
        long int doctor_id;
        int years_of_experience;
        double base_salary;
        double bonus;

    public:
    //constructor 
    Doctor();

    // getters
    std::string getDocFName();
    std::string getDocLName();
    std::string getSpecialty();
    long int getId();
    int getExperience();
    double getBSalary();
    double getBonus();

    // setters
    void setDocFName(std::string dFname);
    void setDocLName(std::string dLname);
    void setSpecialty(std::string specialty);
    void setId(long int docID);
    void setExperience(int experience);
    void setBSalary(double baseSalary);
    void setBonus(double bonus);

    // methods
    double calculate_salary();//calculate the salary 
    void print_Doctor_info();

};

#endif