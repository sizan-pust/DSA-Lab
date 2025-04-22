#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;
int queue[MAX_SIZE], front = 0, rear = -1;

void clearScreen() { system("CLS"); }

bool isFull() { return rear == MAX_SIZE - 1; }
bool isEmpty() { return front > rear; }

void enqueue(int val) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    queue[++rear] = val;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << queue[front++] << " dequeued from queue.\n";
}

void display() {
    if (isEmpty()) cout << "Queue is empty!\n";
    else {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main() {
    string input; int val, choice;

    cout << "Enter initial elements (space-separated): ";
    getline(cin, input);
    stringstream ss(input);
    while (ss >> val) enqueue(val);

    clearScreen(); display();

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                clearScreen(); display();
                cout << "Enter value to enqueue: ";
                cin >> val;
                enqueue(val);
                clearScreen(); display();
                break;

            case 2:
                clearScreen(); display();
                dequeue();
                display();
                break;

            case 3:
                cout << "Exited\n";
                break;

            default:
                cout << "Invalid option!\n";
        }
    } while (choice != 3);

    return 0;
}
