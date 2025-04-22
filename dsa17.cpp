#include <iostream>
using namespace std;

const int MAX = 100;

struct Element {
    int value;
    int priority;
};

Element pq[MAX];
int size = 0;

// Insert element in priority order (highest priority = lowest number)
void enqueue(int val, int pri) {
    if (size == MAX) {
        cout << "Queue is full!\n";
        return;
    }

    int i = size - 1;
    while (i >= 0 && pq[i].priority > pri) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].value = val;
    pq[i + 1].priority = pri;
    size++;

    cout << "Inserted: " << val << " with priority " << pri << endl;
}

// Remove element with highest priority (lowest priority value)
void dequeue() {
    if (size == 0) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Deleted: " << pq[0].value << " with priority " << pq[0].priority << endl;

    for (int i = 1; i < size; i++)
        pq[i - 1] = pq[i];

    size--;
}

// Display the priority queue
void display() {
    if (size == 0) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "\nPriority Queue:\nValue\tPriority\n";
    for (int i = 0; i < size; i++)
        cout << pq[i].value << "\t" << pq[i].priority << endl;
}

int main() {
    int choice, val, pri;

    do {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value and priority: ";
                cin >> val >> pri;
                enqueue(val, pri);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
