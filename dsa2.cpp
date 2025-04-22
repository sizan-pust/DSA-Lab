#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_SIZE = 100;
void display(int arr[], int size)
{
    cout << "The array list is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size = 0;
    int c;
    int arr[MAX_SIZE];
    cout << "Enter your Elements: ";
    while (cin.peek() != '\n')
    {
        if (size < MAX_SIZE)
        {
            cin >> arr[size++];
        }
        else
        {
            cout << "Size limit reached!";
            break;
        }
    }
    cin.ignore();
    while (true)
    {
        display(arr, size);
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Exit" << endl;
        cout << "choose an option: ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            system("CLS");
            display(arr, size);
            int p, d;
            cout << "Enter position and element: ";
            cin >> p >> d;
            if (p >= 0 && p <= size && size < MAX_SIZE)
            {
                p = p - 1;
                for (int i = size; i > p; i--)
                {

                    arr[i] = arr[i - 1];
                }
                arr[p] = d;
                size++;
                system("CLS");
                cout << "After Insertion\n";
            }
            else
            {
                cout << "Invalid Position\n";
                system("pause");
                system("CLS");
            }
            break;
        }

        case 2:
        {
            system("CLS");
            display(arr, size);
            int p;
            cout << "Enter position: ";
            cin >> p;
            if (p >= 0 && p < size)
            {
                p = p - 1;
                for (int i = p; i < size - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                size--;
                system("CLS");
                cout << "After Deletion\n";
            }
            else
            {

                cout << "Invalid Position";
                system("pause");
                system("CLS");
            }
            break;
        }
        case 3:
            system("CLS");
            cout << "program exited";
            return 0;
        default:
            cout << "Invalid position";
            system("pause");
            system("CLS");
        }
    }
    return 0;
}
