#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person() {
        name = "";
        age = 0;
    }

    void getPersonDetails() {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }

    void showPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Patient class inherits Person
class Patient : public Person {
private:
    int patientID;
    string disease;

public:
    void addPatient() {
        cout << "\nEnter Patient ID: ";
        cin >> patientID;
        cin.ignore();

        getPersonDetails();

        cout << "Enter disease: ";
        getline(cin, disease);

        cout << "\nPatient added successfully!\n";
    }

    void displayPatient() {
        cout << "\n--- Patient Details ---\n";
        cout << "Patient ID: " << patientID << endl;
        showPersonDetails();
        cout << "Disease: " << disease << endl;
    }
};

// Doctor class inherits Person
class Doctor : public Person {
private:
    int doctorID;
    string specialization;

public:
    void addDoctor() {
        cout << "\nEnter Doctor ID: ";
        cin >> doctorID;
        cin.ignore();

        getPersonDetails();

        cout << "Enter specialization: ";
        getline(cin, specialization);

        cout << "\nDoctor added successfully!\n";
    }

    void displayDoctor() {
        cout << "\n--- Doctor Details ---\n";
        cout << "Doctor ID: " << doctorID << endl;
        showPersonDetails();
        cout << "Specialization: " << specialization << endl;
    }
};

// Main function
int main() {
    Patient patient;
    Doctor doctor;

    int choice;
    bool patientAdded = false;
    bool doctorAdded = false;

    do {
        cout << "\n================================\n";
        cout << "   HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patient\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctor\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                patient.addPatient();
                patientAdded = true;
                break;

            case 2:
                if (patientAdded)
                    patient.displayPatient();
                else
                    cout << "\nNo patient record available.\n";
                break;

            case 3:
                doctor.addDoctor();
                doctorAdded = true;
                break;

            case 4:
                if (doctorAdded)
                    doctor.displayDoctor();
                else
                    cout << "\nNo doctor record available.\n";
                break;

            case 5:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}