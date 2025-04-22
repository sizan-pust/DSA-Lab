#include <iostream>
#include <ctime>
using namespace std;

void fillArray(int* arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}

void displayArray(int* arr, int size) {
    cout << "Array list: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void searchValue(int* arr, int size, int value) {
    int count = 0;
    cout << "Value " << value << " found at positions: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << i + 1 << " ";  // 1-based index
            count++;
        }
    }
    if (count == 0) {
        cout << "None";
    }
    cout << "\nOccurrences: " << count << endl;
}

int main() {
    int size, value;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    fillArray(arr, size);
    displayArray(arr, size);

    cout << "\nEnter a value to search: ";
    cin >> value;

    searchValue(arr, size, value);

    delete[] arr;
    return 0;
}
