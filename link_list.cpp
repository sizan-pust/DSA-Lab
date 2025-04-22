#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Function prototypes
void insert(Node *&head, int value);
void remove(Node *&head, int value);
void display(Node *head);

int main()
{
    Node *head = nullptr; // Initialize the linked list
    int choice, value;
    display(head);
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            insert(head, value);
            system("cls");
            display(head);
            break;
        case 2:
            cout << "Enter the value to delete: ";
            cin >> value;
            remove(head, value);
            system("cls");
            display(head);
            break;

        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Insert function: Adds an element at the end of the list
void insert(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head=newNode;
        /*Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;*/
    }
    cout << "Element inserted successfully.\n";
}

// Remove function: Deletes the first occurrence of an element
void remove(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Element deleted successfully.\n";
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Element not found in the list.\n";
    }
    else
    {
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Element deleted successfully.\n";
    }
}

// Display function: Prints the linked list
void display(Node *head)
{
    cout<<"List: ";
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
