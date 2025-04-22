#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX = 100;
int stack[MAX], top = -1;

void push(int val) {
    if (top >= MAX - 1)
        cout << "Stack overflow\n";
    else
        stack[++top] = val;
}

int pop() {
    if (top < 0) {
        cout << "Stack underflow\n";
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix( string &exp) {
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            push(ch - '0'); // convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }

    return pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (e.g., 23*54*+9-): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;
    return 0;
}
