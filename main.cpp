#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

vector<Student> students;

void loadStudents() {
    ifstream file("students.txt");
    if (file.is_open()) {
        string name;
        int grade;
        while (file >> name >> grade) {
            Student student(name, grade);
            students.push_back(student);
        }
        file.close();
    }
}

void saveStudents() {
    ofstream file("students.txt");
    for (int i = 0; i < students.size(); i++) {
        file << students[i].getName() << " " << students[i].getGrade() << endl;
    }
    file.close();
}

void addStudent() {
    cout << "Enter student name: ";
    string name;
    cin >> name;
    cout << "Enter student grade: ";
    int grade;
    cin >> grade;
    Student student(name, grade);
    students.push_back(student);
    cout << "Student record added successfully!" << endl;
    saveStudents();
}

void displayAll() {
    cout << "Student records:" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].getName() << " " << students[i].getGrade() << endl;
    }
}

void displaySpecific() {
    cout << "Enter student name or grade to display: ";
    string search;
    cin >> search;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == search || students[i].getGrade() == stoi(search)) {
            cout << "Student record:" << endl;
            cout << students[i].getName() << " " << students[i].getGrade() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Student record not found." << endl;
    }
}

void editStudent() {
    cout << "Enter student name or grade to edit: ";
    string search;
    cin >> search;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == search || students[i].getGrade() == stoi(search)) {
            cout << "Enter new student name: ";
            string newName;
            cin >> newName;
            students[i].setName(newName);
            cout << "Enter new student grade: ";
            int newGrade;
            cin >> newGrade;
            students[i].setGrade(newGrade);
            cout << "Student record updated successfully!" << endl;
            saveStudents();
            return;
        }
    }
    cout << "Student record not found." << endl;
}

void deleteStudent() {
    cout << "Enter student name or grade to delete: ";
    string search;
    cin >> search;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == search || students[i].getGrade() == stoi(search)) {
            students.erase(students.begin() + i);
            cout << "Student record deleted successfully!" << endl;
            saveStudents();
            return;
        }
    }
    cout << "Student record not found." << endl;
}

void calculateAverage() {
    int sum = 0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i].getGrade();
    }
    double average = static_cast<double>(sum) / students.size();
    cout << "Average grade: " << average << endl;
}

bool compareByName(Student a, Student b) {
    return a.getName() < b.getName();
}

void sortByName() {
    sort(students.begin(), students.end(), compareByName);
    cout << "Student records sorted by name." << endl;
}

bool compareByGrade(Student a, Student b) {
    return a.getGrade() < b.getGrade();
}

void sortByGrade() {
    sort(students.begin(), students.end(), compareByGrade);
    cout << "Student records sorted by grade." << endl;
}

void showMenu() {
    cout << "Select an option:" << endl;
    cout << "1. Add student record" << endl;
    cout << "2. Display all student records" << endl;
    cout << "3. Display specific student record" << endl;
    cout << "4. Edit student record" << endl;
    cout << "5. Delete student record" << endl;
    cout << "6. Calculate average grade" << endl;
    cout << "7. Sort student records by name" << endl;
    cout << "8. Sort student records by grade" << endl;
    cout << "9. Exit" << endl;
}

int main() {
    loadStudents();
    bool exit = false;
    while (!exit) {
        showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                displaySpecific();
                break;
            case 4:
                editStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                calculateAverage();
                break;
            case 7:
                sortByName();
                break;
            case 8:
                sortByGrade();
                break;
            case 9:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
