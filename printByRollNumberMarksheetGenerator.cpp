#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

const int NUM_STUDENTS = 10;
const int NUM_SUBJECTS = 5;
const int MAX_MARKS = 50;
const float PASS_PERCENTAGE = 40.0f;

// Structure to hold student info
struct Student {
    int rollNumber;
    string name;
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float percentage;
    string result;
};

// Generate random marks
int genMarks() {
    return rand() % (MAX_MARKS + 1);
}

// Calculate total, percentage, and result
void calcResult(Student& student) {
    student.totalMarks = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student.totalMarks += student.marks[i];
    }
    student.percentage = (student.totalMarks * 100.0) / (NUM_SUBJECTS * MAX_MARKS);
    student.result = (student.percentage >= PASS_PERCENTAGE) ? "Pass" : "Fail";
}

// Print single student's marksheet
void printMarks(const Student& student) {
    cout << "\n================== Marksheet ==================\n\n";
    cout << left << setw(10) << "Roll No"
        << left << setw(20) << "Name"
        << left << setw(10) << "Total"
        << left << setw(12) << "Percentage"
        << left << setw(10) << "Result" << endl;
    cout << "------------------------------------------------------------\n";
    cout << left << setw(10) << student.rollNumber
        << left << setw(20) << student.name
        << left << setw(10) << student.totalMarks
        << left << fixed << setprecision(2) << setw(12) << student.percentage << "%"
        << left << setw(10) << student.result << endl;
    cout << "------------------------------------------------------------\n";
}

// Print marks by roll number
void printByRoll(Student students[]) {
    int userInput;
    cout << "Enter Roll Number: ";
    cin >> userInput;

    bool found = false;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (userInput == students[i].rollNumber) {
            printMarks(students[i]);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid roll number. Try again.\n";
        printByRoll(students);  // Re-prompt
    }
}

int main() {
    srand(time(NULL));  // Seed random number generator

    // Predefined student names and roll numbers
    Student students[NUM_STUDENTS] = {
        {1, "John Doe", {0}, 0, 0.0f, ""},
        {2, "Alice Smith", {0}, 0, 0.0f, ""},
        {3, "Bob Johnson", {0}, 0, 0.0f, ""},
        {4, "David Brown", {0}, 0, 0.0f, ""},
        {5, "Eva Davis", {0}, 0, 0.0f, ""},
        {6, "Frank Miller", {0}, 0, 0.0f, ""},
        {7, "Grace Wilson", {0}, 0, 0.0f, ""},
        {8, "Henry Moore", {0}, 0, 0.0f, ""},
        {9, "Ivy Taylor", {0}, 0, 0.0f, ""},
        {10, "Jack Anderson", {0}, 0, 0.0f, ""}
    };

    // Assign random marks and calculate results
    for (int i = 0; i < NUM_STUDENTS; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            students[i].marks[j] = genMarks();
        }
        calcResult(students[i]);
    }

    // Print by roll number
    printByRoll(students);

    return 0;
}
