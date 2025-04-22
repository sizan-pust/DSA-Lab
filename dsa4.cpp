#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

const int MAX_FILE_SIZE = 10000;

int main() {
    string fname;

    int v = 0, c = 0, d = 0, o = 0;
    char f[MAX_FILE_SIZE];
    cout << "Enter the file name: ";
    cin >> fname;

    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Could not open the file!" << endl;
        return 1;
    }
    int i=0;
    char ch;
    while (file.get(ch)&& i<MAX_FILE_SIZE)
        {
            f[i++]=ch;
        }
        file.close();
        for (int i = 0; i < MAX_FILE_SIZE && f[i]!='\0'; i++)
            {
            char ch = f[i];

        if (isalpha(ch))
        {
            char lower = tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                v++;
            } else {
                c++;
            }
        }
        else if (isdigit(ch))
            {
            d++;
        } else if (!isspace(ch)) {
            o++;
        }
    }
    cout << "Total: " << v+c+d+o << endl;
    cout << "Number of Vowels: " << v << endl;
    cout << "Number of Consonants: " << c << endl;
    cout << "Number of Digits: " << d << endl;
    cout << "Other Special characters: " << o << endl;



    return 0;
}
