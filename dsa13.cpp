#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int roll;
    float marks;
};

bool compareMarks(const Student& a, const Student& b) {
    return a.marks > b.marks;
}

void display(const vector<Student>& students) {
    cout << "\n" << setw(25) << left << "Name" << setw(20) << "Roll" << setw(10) << "Marks" << endl;
    cout << string(55, '-') << endl;

    for (int i = 0; i < students.size(); i++) {
        cout << setw(25) << left << students[i].name
             << setw(20) << students[i].roll
             << setw(10) << students[i].marks << endl;
    }
}

void addStudent(vector<Student>& students) {
    Student s;
    cout << "\nEnter details for the student:\n";
    cout << "Name: ";
    //cin.ignore();
    cin >> ws;
    getline(cin, s.name);
    cout << "Roll Number: ";
    cin >> s.roll;
    cout << "Marks: ";
    cin >> s.marks;

    students.push_back(s);
}

int main() {
    vector<Student> students;
    char choice;

    do {
        addStudent(students);
        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    while (true) {
        system("CLS");

        sort(students.begin(), students.end(), compareMarks);
        display(students);

        cout << "\nChoose an option:\n";
        cout << "1. Insert new student information\n";
        cout << "2. Delete an existing student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        if (option == 1) {
            addStudent(students);
        } else if (option == 2) {
            int roll;
            cout << "\nEnter the roll number of the student to delete: ";
            cin >> roll;

            auto it = find_if(students.begin(), students.end(),
                              [roll](const Student& student) { return student.roll == roll; });

            if (it != students.end()) {
                students.erase(it);
                cout << "\nStudent with roll number " << roll << " deleted successfully!\n";
            } else {
                cout << "\nStudent with roll number " << roll << " not found!\n";
            }
        } else if (option == 3) {
            cout << "\nExiting the program";
            break;
        } else {
            cout << "\nInvalid option! Please try again.\n";
        }
    }

    return 0;
}
