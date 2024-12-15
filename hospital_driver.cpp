#include "hospital.h"
#include <iostream>
#include <limits>

void make_selection(int&);
void hospital_app(int, Hospital&);


int main() {
    int user_selection{0};
    Hospital montreal_hospital;

    // prompting the user to make a selection
    make_selection(user_selection);
    hospital_app(user_selection, montreal_hospital);

    return 0;
}

void make_selection(int &selection) {
    bool selecting = true;
    while (selecting) {
        std::cout << "****** Welcome to your hospital app ******" << "\n\n\n"
                  << "Please select one of the following options: \n"
                  << "1. Find the oldest patient.\n"
                  << "2. Report the number of critical patients.\n"
                  << "3. Show patients data by ID.\n"
                  << "4. Show doctor data by ID.\n"
                  << "5. Show assigned doctor for a specific patient.\n"
                  << "6. Show assigned patients for a given doctor.\n"
                  << "7. Exit.\n"
                  << "Your selection: ";
        
        std::cin >> selection;

        if (std::cin.fail() || selection < 1 || selection > 7) {
            std::cin.clear(); //clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard invalid input
            std::cout << "Invalid option, please try again.\n";

        } else {
            selecting = false; //valid input, exit loop
        }
    }
}

void hospital_app(int selection, Hospital &montreal_hospital) {
    long int id{0};
    switch (selection) {
        case 1:
            montreal_hospital.find_oldest_patient();
            break;
        case 2:
            std::cout << "The number of critical patients is: " << montreal_hospital.count_critical_patients() << std::endl;
            break;
        case 3:
            std::cout << "Enter patient ID: ";
            std::cin >> id;
            std::cout << std::endl << "The patient with matching ID is: \n " << std::endl;
            montreal_hospital.show_patient_by_id(id);
            break;
        case 4:
            std::cout << "Enter doctor ID: ";
            std::cin >> id;
            montreal_hospital.show_doctor_by_id(id);
            break;
        case 5:
            std::cout << "Enter patient ID: ";
            std::cin >> id;
            montreal_hospital.show_assigned_doctor(id);
            break;
        case 6:
            std::cout << "Enter doctor ID: ";
            std::cin >> id;
            montreal_hospital.show_assigned_patients(id);
            break;
        case 7:
            std::cout << "Have a good day!";
            break;
        default:
            std::cout << "Something went wrong, please try again.";
            break;
    }
}

