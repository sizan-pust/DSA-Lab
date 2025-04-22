#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE], top = -1;

void clearScreen() { system("CLS"); }

bool isFull() { return top == MAX_SIZE - 1; }
bool isEmpty() { return top == -1; }

void insertAt(int position, int element) {
    if (position < 1 || position > top + 2) {
        cout << "Invalid position!" << endl;
        return;
    }
    int temp[MAX_SIZE], tempTop = -1;
    for (int i = 1; i < position; i++) temp[++tempTop] = stack[top--];
    stack[++top] = element;
    while (tempTop >= 0) stack[++top] = temp[tempTop--];
}

void deleteAt(int position) {
    if (position < 1 || position > top + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    int temp[MAX_SIZE], tempTop = -1;
    for (int i = 1; i < position; i++) temp[++tempTop] = stack[top--];
    cout << stack[top--] << " deleted from stack." << endl;
    while (tempTop >= 0) stack[++top] = temp[tempTop--];
}

void display() {
    if (isEmpty()) cout << "Stack is empty!" << endl;
    else {
        cout << "Your list: ";
        for (int i = top; i >= 0; i--) cout << stack[i] << " ";
        cout << endl;
    }
}

int main() {
    string input; int value, position, choice;
    cout << "Enter your elements (space-separated): ";
    getline(cin, input);
    stringstream ss(input);
    while (ss >> value) insertAt(top + 2, value);

    clearScreen(); display();

    do {
        cout << "\n1. Insert\n2. Delete\n3. Exit\nEnter your option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                clearScreen(); display();
                cout << "Enter position and value to insert: ";
                cin >> position >> value;
                insertAt(position, value); clearScreen(); display(); break;
            }
            case 2: {
                clearScreen(); display();
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAt(position); clearScreen(); display(); break;
            }
            case 3: cout << "Exited" << endl; break;
            default: cout << "Invalid option!" << endl;
        }
    } while (choice != 3);

    return 0;
}
