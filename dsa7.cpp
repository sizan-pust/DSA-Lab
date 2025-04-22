#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        // Find the index of the minimum element
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum with the first element of the unsorted part
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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

    selectionSort(arr, size);
    displayArray(arr, size);

    return 0;
}
