#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1000;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    string inFileName, outFileName;
    int arr[MAX], n = 0;

    // Get file names from user
    cout << "Enter input file name: ";
    cin >> inFileName;
    cout << "Enter output file name: ";
    cin >> outFileName;

    // Open files
    ifstream inFile(inFileName);
    ofstream outFile(outFileName);

    if (!inFile) {
        cout << "Error: Cannot open " << inFileName << endl;
        return 1;
    }

    // Read integers from file
    while (inFile >> arr[n] && n < MAX) n++;
    inFile.close();

    // Sort array
    insertionSort(arr, n);

    // Write sorted data to output file
    for (int i = 0; i < n; i++)
        outFile << arr[i] << " ";
    outFile.close();

    cout << "Sorted data saved to " << outFileName << endl;
    return 0;
}
