#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    cout << "Enter your elements : ";

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

    bubbleSort(arr, size);
    displayArray(arr, size);

    return 0;
}
