#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    cout << "Before Swap:\n";
    cout << "x = " << x << ", y = " << y << endl;

    swap(&x, &y);  // passing addresses

    cout << "After Swap:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
