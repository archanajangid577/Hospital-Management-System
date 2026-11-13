#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    void getDetails() {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }

    void showDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Patient Class
class Patient : public Person {
public:
    int patientID;
    string disease;

    void addPatient(int id) {
        patientID = id;

        cout << "\nEnter Patient Details\n";

        getDetails();

        cout << "Enter Disease: ";
        getline(cin, disease);

        cout << "\nPatient Registered Successfully!\n";
    }

    void displayPatient() {
        cout << "\nPatient ID: " << patientID << endl;
        showDetails();
        cout << "Disease: " << disease << endl;
    }
};

// Doctor Class
class Doctor : public Person {
public:
    int doctorID;
    string specialization;
    double fee;

    void addDoctor(int id) {
        doctorID = id;

        cout << "\nEnter Doctor Details\n";

        getDetails();

        cout << "Enter Specialization: ";
        getline(cin, specialization);

        cout << "Enter Consultation Fee: ";
        cin >> fee;
        cin.ignore();

        cout << "\nDoctor Added Successfully!\n";
    }

    void displayDoctor() {
        cout << "\nDoctor ID: " << doctorID << endl;
        showDetails();

        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: Rs. " << fee << endl;
    }
};

// Appointment Class
class Appointment {
public:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;

    void bookAppointment(int a, int p, int d, string dt) {
        appointmentID = a;
        patientID = p;
        doctorID = d;
        date = dt;
    }

    void displayAppointment() {
        cout << "\nAppointment ID: " << appointmentID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Date: " << date << endl;
    }
};

// Hospital Management Class
class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    int pID = 1;
    int dID = 1;
    int aID = 1;

public:

    // MODULE 1: Patient Management

    void registerPatient() {
        Patient p;
        p.addPatient(pID++);
        patients.push_back(p);
    }

    void showPatients() {
        if (patients.empty()) {
            cout << "\nNo Patient Records Found!\n";
            return;
        }

        for (auto &p : patients) {
            p.displayPatient();
        }
    }

    // MODULE 2: Doctor Management

    void addDoctor() {
        Doctor d;
        d.addDoctor(dID++);
        doctors.push_back(d);
    }

    void showDoctors() {
        if (doctors.empty()) {
            cout << "\nNo Doctor Records Found!\n";
            return;
        }

        for (auto &d : doctors) {
            d.displayDoctor();
        }
    }

    // MODULE 3: Appointment Management

    void bookAppointment() {
        int p, d;
        string date;

        if (patients.empty() || doctors.empty()) {
            cout << "\nAdd Patient and Doctor First!\n";
            return;
        }

        cout << "\nEnter Patient ID: ";
        cin >> p;

        cout << "Enter Doctor ID: ";
        cin >> d;
        cin.ignore();

        bool patientFound = false;
        bool doctorFound = false;

        for (auto &x : patients) {
            if (x.patientID == p)
                patientFound = true;
        }

        for (auto &x : doctors) {
            if (x.doctorID == d)
                doctorFound = true;
        }

        if (!patientFound || !doctorFound) {
            cout << "\nInvalid Patient or Doctor ID!\n";
            return;
        }

        cout << "Enter Appointment Date: ";
        getline(cin, date);

        Appointment a;
        a.bookAppointment(aID++, p, d, date);

        appointments.push_back(a);

        cout << "\nAppointment Booked Successfully!\n";
    }

    void showAppointments() {
        if (appointments.empty()) {
            cout << "\nNo Appointments Found!\n";
            return;
        }

        for (auto &a : appointments) {
            a.displayAppointment();
        }
    }

    void cancelAppointment() {
        int id;

        cout << "\nEnter Appointment ID: ";
        cin >> id;

        for (int i = 0; i < appointments.size(); i++) {
            if (appointments[i].appointmentID == id) {

                appointments.erase(appointments.begin() + i);

                cout << "\nAppointment Cancelled Successfully!\n";
                return;
            }
        }

        cout << "\nAppointment Not Found!\n";
    }

    // MODULE 4: Billing System

    void generateBill() {
        int p, d;
        double fee = 0;

        cout << "\nEnter Patient ID: ";
        cin >> p;

        cout << "Enter Doctor ID: ";
        cin >> d;

        bool patientFound = false;
        bool doctorFound = false;

        for (auto &x : patients) {
            if (x.patientID == p)
                patientFound = true;
        }

        for (auto &x : doctors) {
            if (x.doctorID == d) {
                doctorFound = true;
                fee = x.fee;
            }
        }

        if (!patientFound || !doctorFound) {
            cout << "\nInvalid Patient or Doctor ID!\n";
            return;
        }

        cout << "\n========== HOSPITAL BILL ==========\n";

        cout << "Patient ID: " << p << endl;
        cout << "Doctor ID: " << d << endl;

        cout << "Consultation Fee: Rs. "
             << fixed << setprecision(2) << fee << endl;

        cout << "Total Amount: Rs. " << fee << endl;

        cout << "===================================\n";
    }

    // MAIN MENU

    void menu() {
        int choice;

        do {
            cout << "\n====================================\n";
            cout << "      HOSPITAL MANAGEMENT SYSTEM\n";
            cout << "====================================\n";

            cout << "1. Register Patient\n";
            cout << "2. View Patients\n";
            cout << "3. Add Doctor\n";
            cout << "4. View Doctors\n";
            cout << "5. Book Appointment\n";
            cout << "6. View Appointments\n";
            cout << "7. Cancel Appointment\n";
            cout << "8. Generate Patient Bill\n";
            cout << "0. Exit\n";

            cout << "====================================\n";

            cout << "Enter Your Choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {

                case 1:
                    registerPatient();
                    break;

                case 2:
                    showPatients();
                    break;

                case 3:
                    addDoctor();
                    break;

                case 4:
                    showDoctors();
                    break;

                case 5:
                    bookAppointment();
                    break;

                case 6:
                    showAppointments();
                    break;

                case 7:
                    cancelAppointment();
                    break;

                case 8:
                    generateBill();
                    break;

                case 0:
                    cout << "\nThank You For Using Hospital Management System!\n";
                    break;

                default:
                    cout << "\nInvalid Choice! Try Again.\n";
            }

        } while (choice != 0);
    }
};

// Main Function
int main() {

    Hospital h;

    h.menu();

    return 0;
}