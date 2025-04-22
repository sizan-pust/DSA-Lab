#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE], top = -1;

void clearScreen() { system("CLS"); }

bool isFull() { return top == MAX_SIZE - 1; }
bool isEmpty() { return top == -1; }

void insertAt( int element) {
    
    if (isFull()) cout << "Stack Overflow!" << endl;
    else stack[++top] = element;
}

void deleteAt() {
    
    if (isEmpty()) cout << "Stack Underflow!" << endl;
    else cout << stack[top--] << " popped from stack." << endl;
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
    string input; int value, choice;
    cout << "Enter your elements (space-separated): ";
    getline(cin, input);
    stringstream ss(input);
    while (ss >> value) insertAt(value);

    clearScreen(); display();

    do {
        cout << "\n1. Insert\n2. Delete\n3. Exit\nEnter your option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                clearScreen(); display();
                cout << "Enter value to insert: ";
                cin  >> value;
                insertAt(value); clearScreen(); display(); break;
            }
            case 2: {
                clearScreen(); display();
                cout << "Enter the element to delete: ";
            
                deleteAt(); clearScreen(); display(); break;
            }
            case 3: cout << "Exited" << endl; break;
            default: cout << "Invalid option!" << endl;
        }
    } while (choice != 3);

    return 0;
}
