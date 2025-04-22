#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

void sortArr(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void show(int a[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void insertVal(int a[], int &n, int val) {
    if (n >= MAX) {
        cout << "Array full!\n";
        return;
    }
    int i = n - 1;
    while (i >= 0 && a[i] > val) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = val;
    n++;
    cout << "Inserted " << val << ".\n";
}

void delVal(int a[], int &n, int val) {
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == val) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Value not found!\n";
        return;
    }
    for (int i = idx; i < n - 1; ++i) {
        a[i] = a[i + 1];
    }
    n--;
    cout << "Deleted " << val << ".\n";
}

int main() {
    int a[MAX], n = 0;

    cout << "Enter elements: ";
    while (cin.peek() != '\n') {
        if (n < MAX) {
            cin >> a[n++];
        } else {
            cout << "Max size reached!\n";
            break;
        }
    }
    cin.ignore();
    system("CLS");
    sortArr(a, n);
    cout<<"Sorted ";
    show(a, n);

    int ch;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Delete\n3. Exit\nChoice: ";
        cin >> ch; 
        if (ch == 1) {
           
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            insertVal(a, n, val);
            system("CLS");
            cout<<"Sorted ";
            show(a, n);
        } else if (ch == 2) {
            system("CLS");
            show(a, n);
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            delVal(a, n, val);
          
            cout<<"Sorted ";
            show(a, n);
        } 
        else if (ch == 3) {
            cout<<"program exited";
                return 0;
        }
            else if (ch != 3) {
            cout << "Invalid!\n";
        }

    } while (ch != 4);

    return 0;
}
