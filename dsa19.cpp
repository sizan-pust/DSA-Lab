#include <iostream>
using namespace std;

const int MAX = 100;
int tree[MAX];

// Initialize tree with -1 (indicating empty)
void initTree() {
    for (int i = 0; i < MAX; i++)
        tree[i] = -1;
}

// Insert root node
void insertRoot(int value) {
    if (tree[0] != -1)
        cout << "Root already exists!\n";
    else
        tree[0] = value;
}

// Insert left child
void insertLeft(int parentIndex, int value) {
    int left = 2 * parentIndex + 1;
    if (tree[parentIndex] == -1)
        cout << "No parent at index " << parentIndex << "!\n";
    else
        tree[left] = value;
}

// Insert right child
void insertRight(int parentIndex, int value) {
    int right = 2 * parentIndex + 2;
    if (tree[parentIndex] == -1)
        cout << "No parent at index " << parentIndex << "!\n";
    else
        tree[right] = value;
}

// Display tree in level order
void display() {
    cout << "\nTree (level-order): ";
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1)
            cout << tree[i] << " ";
    }
    cout << endl;
}

int main() {
    initTree();
// root index 0;
    insertRoot(1);
    insertLeft(0, 2);
    insertRight(0, 3);
    insertLeft(1, 4);
    insertRight(1, 5);
    insertLeft(2, 6);

    display();

    return 0;
}
