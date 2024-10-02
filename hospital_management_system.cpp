#include <iostream>
#include <string>

using namespace std;

// Doctor
struct Doctor {
    string name;
    int fees;
    string specialization;
    int age;
};

// Staff
struct Staff {
    string name;
    int fees;
    string assignedPatient;
    int age;
};

// Patient
struct Patient {
    string name;
    int daysAdmitted;
    string treatedByDoctor;
    string checkedByStaff;
    int age;
    int totalCharges; // Calculated total charges
};

// Medicine
struct Medicine {
    string name;
    int price;
};

int main() {
    const int maxPersons = 100;  // Max limit for patients, staff, and doctors
    const int chargePerDay = 500;  // Charge per day of stay
    Patient patients[maxPersons];
    Staff staffs[maxPersons];
    Doctor doctors[maxPersons];
    Medicine medicines[maxPersons];

    int patientCount = 0;

    while (true) {
        cout << "\nSelect any Option:\n";
        cout << "1: Print Patient Details\n";
        cout << "2: Admit Patient\n";
        cout << "3: Exit\n";
        cout << "Your input: ";

        int userInput;
        cin >> userInput;

        if (userInput == 1) {  // Print Patient Details
            string patientName;
            cout << "Enter patient name to print details: ";
            cin >> patientName;

            bool found = false;
            for (int i = 0; i < patientCount; i++) {
                if (patientName == patients[i].name) {
                    cout << "Patient's Name: " << patients[i].name << endl;
                    cout << "Patient's Age: " << patients[i].age << endl;
                    cout << "Days Admitted: " << patients[i].daysAdmitted << endl;
                    cout << "Treated By Doctor: " << patients[i].treatedByDoctor << endl;
                    cout << "Checked By Staff: " << patients[i].checkedByStaff << endl;
                    cout << "Total Charges: $" << patients[i].totalCharges << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Patient not found: " << patientName << endl;
            }
        }
        else if (userInput == 2) {  // Admit Patient
            if (patientCount < maxPersons) {
                Patient newPatient;

                cout << "Enter Patient's Name: ";
                cin >> newPatient.name;
                cout << "Enter Patient's Age: ";
                cin >> newPatient.age;
                cout << "Enter Number of Days Admitted: ";
                cin >> newPatient.daysAdmitted;
                cout << "Enter Doctor's Name Treating Patient: ";
                cin >> newPatient.treatedByDoctor;
                cout << "Enter Staff's Name Checking Patient: ";
                cin >> newPatient.checkedByStaff;

                // Calculate total charges: (Per day charges + doctor fees + staff fees)
                int medicineCharges = 0;
                int numberOfMedicines;
                cout << "Enter the number of medicines prescribed: ";
                cin >> numberOfMedicines;
                for (int i = 0; i < numberOfMedicines; i++) {
                    cout << "Enter price of medicine " << (i + 1) << ": ";
                    cin >> medicines[i].price;
                    medicineCharges += medicines[i].price;
                }

                int doctorFees = 0, staffFees = 0;
                cout << "Enter Doctor's Fees: ";
                cin >> doctorFees;
                cout << "Enter Staff's Fees: ";
                cin >> staffFees;

                newPatient.totalCharges = (chargePerDay * newPatient.daysAdmitted) + doctorFees + staffFees + medicineCharges;

                patients[patientCount] = newPatient;
                patientCount++;

                cout << "Patient admitted successfully with total charges: $" << newPatient.totalCharges << endl;
            }
            else {
                cout << "Cannot admit more patients, capacity reached." << endl;
            }
        }
        else if (userInput == 3) {  // Exit
            cout << "Exiting the program." << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}
