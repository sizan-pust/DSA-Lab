#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

void print(Node *&head){
    Node* temp = head; // Temporary pointer to traverse the list
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}
int main() {
    // Step 1: Create nodes with pre-defined values
    Node* head = new Node();    // First node
    Node* second = new Node(); // Second node
    Node* third = new Node();  // Third node

    // Step 2: Assign data to each node
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Step 3: Link the nodes
    head->next = second;
    second->next = third;
    third->next = nullptr;

    // Step 4: Print the linked list
    print(head);

    // Step 5: Free memory
    delete head;
    delete second;
    delete third;

    return 0;
}
