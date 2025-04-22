#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the inorder successor (smallest in right subtree)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node in BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root; // Base case: Empty tree or node not found
    }

    // Find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found - Handle deletion

        // Case 1: No child (Leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child (Left or Right)
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = minValueNode(root->right); // Get inorder successor
        root->data = temp->data; // Copy inorder successor's data
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root; // Return the updated root
}

// Function to print BST (Inorder Traversal)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal of BST before deletion: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder Traversal of BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
