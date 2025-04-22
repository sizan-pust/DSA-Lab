#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};

// Build binary tree level by level
Node* buildTree() {
    int val;
    cout << "Enter root value: ";
    cin >> val;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front(); q.pop();

        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            current->left = new Node(val);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            current->right = new Node(val);
            q.push(current->right);
        }
    }

    return root;
}

// In-order traversal (LNR)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Pre-order traversal (NLR)
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (LRN)
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = buildTree();

    cout << "\nIn-order Traversal: ";
    inorder(root);
    
    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}
