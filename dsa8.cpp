#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int size) {
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    cout << "Enter your elements (press Enter to finish): ";

    // Take input until Enter is pressed
    while (cin.peek() != '\n') {
        if (size < MAX_SIZE) {
            cin >> arr[size++];
        } else {
            cout << "Size limit reached!" << endl;
            break;
        }
    }
    cin.ignore(); // Clear newline from buffer

    insertionSort(arr, size);
    displayArray(arr, size);

    return 0;
}
