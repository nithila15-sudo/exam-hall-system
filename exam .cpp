#include <iostream>
using namespace std;

struct Exam {
    string subject;
    string hall;
    string time;
    string invigilator;
};

Exam exams[100];
int countExam = 0;

// 🔍 Check conflicts
bool checkConflict(string hall, string time, string invigilator) {
    for(int i = 0; i < countExam; i++) {
        if(exams[i].hall == hall && exams[i].time == time) {
            cout << "❌ Hall already booked!\n";
            return true;
        }
        if(exams[i].invigilator == invigilator && exams[i].time == time) {
            cout << "❌ Invigilator already assigned!\n";
            return true;
        }
    }
    return false;
}

// ➕ Add Exam
void addExam() {
    string subject, hall, time, invigilator;

    cout << "\nEnter Subject: ";
    cin >> subject;
    cout << "Enter Hall: ";
    cin >> hall;
    cout << "Enter Time: ";
    cin >> time;
    cout << "Enter Invigilator: ";
    cin >> invigilator;

    if(checkConflict(hall, time, invigilator)) {
        return;
    }

    exams[countExam++] = {subject, hall, time, invigilator};
    cout << "✅ Exam added successfully!\n";
}

// 📋 Display Exams
void displayExams() {
    if(countExam == 0) {
        cout << "\nNo exams scheduled!\n";
        return;
    }

    cout << "\n===== Exam Schedule =====\n";
    for(int i = 0; i < countExam; i++) {
        cout << "\nSubject      : " << exams[i].subject;
        cout << "\nHall         : " << exams[i].hall;
        cout << "\nTime         : " << exams[i].time;
        cout << "\nInvigilator  : " << exams[i].invigilator;
        cout << "\n-----------------------------";
    }
}

// ❌ Delete Exam
void deleteExam() {
    string subject;
    cout << "\nEnter subject to delete: ";
    cin >> subject;

    for(int i = 0; i < countExam; i++) {
        if(exams[i].subject == subject) {
            for(int j = i; j < countExam - 1; j++) {
                exams[j] = exams[j + 1];
            }
            countExam--;
            cout << "✅ Exam deleted!\n";
            return;
        }
    }

    cout << "❌ Exam not found!\n";
}

// 🔍 Search Exam
void searchExam() {
    string subject;
    cout << "\nEnter subject to search: ";
    cin >> subject;

    for(int i = 0; i < countExam; i++) {
        if(exams[i].subject == subject) {
            cout << "\nFound!\n";
            cout << "Hall: " << exams[i].hall;
            cout << "\nTime: " << exams[i].time;
            cout << "\nInvigilator: " << exams[i].invigilator << endl;
            return;
        }
    }

    cout << "❌ Not found!\n";
}

// 🧠 Main Menu
int main() {
    int choice;

    do {
        cout << "\n\n===== Exam Hall Management System =====\n";
        cout << "1. Add Exam\n";
        cout << "2. View Exams\n";
        cout << "3. Delete Exam\n";
        cout << "4. Search Exam\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addExam(); break;
            case 2: displayExams(); break;
            case 3: deleteExam(); break;
            case 4: searchExam(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}