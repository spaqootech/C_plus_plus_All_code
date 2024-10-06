//hospital management system oop lab 3 
#include <iostream>
using namespace std;

class person {
public:
    string name;
    int age;
};

class employee : public person {
public:
    string salary;
};

class doctor : public employee {
public:
    string specialty; // Added to define the doctor better
};

class medicine {
public:
    string name;
    string expiry;
    int price;
};

class treat_rec {
public:
    string illness;
    doctor doc;
    medicine pres[3];
};

class patient : public person {
public:
    treat_rec diagnosis; // Fixed the syntax here
};

class admin {
public:
    void show(const patient& ob) { // Use const reference to avoid copying
        cout << "Patient Name: " << ob.name << endl;
        cout << "Illness: " << ob.diagnosis.illness << endl;
        cout << "Doctor Name: " << ob.diagnosis.doc.name << endl;
        cout << "Prescribed Medicine: " << ob.diagnosis.pres[0].name << endl;
    }
};

int main() {

    patient pat;
    pat.name = "OOP Patients";
    pat.age = 30;

    pat.diagnosis.illness = "Flu";
    pat.diagnosis.doc.name = "Dr. Zubair";
    pat.diagnosis.pres[0].name = "Quizz";
    pat.diagnosis.pres[0].expiry = "2025-12-31";
    pat.diagnosis.pres[0].price = 100;

    admin adm;
    adm.show(pat); 

    return 0;
}
