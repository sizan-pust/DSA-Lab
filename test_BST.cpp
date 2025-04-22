#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data= val;
        left= right= nullptr;
    }
};

Node *insertNode(Node *node, int val)
{
     if (node == nullptr)
        return new Node(val);
     if (val < node->data)
        {
            node->left = insertNode(node->left, val);
        }

        else{
            node->right = insertNode(node->right, val);
        }
        return node;
}

Node *minval(Node *node){
Node *cur = node;
while(cur && cur->left!= nullptr){
    cur= cur->left;
}
return cur;
}


Node *deleteNode(Node *node, int val)
{
    if (node == nullptr)
        return node;

    if (val < node->data)
    {
        node->left = deleteNode(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = deleteNode(node->right, val);
    }
    else
    {
        // Case 1: No child (leaf node)
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        // Case 2: One child (only right child exists)
        if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        // Case 3: One child (only left child exists)
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        // Case 4: Two children
        Node *temp = minval(node->right); // Find inorder successor
        node->data = temp->data;          // Replace with successor value
        node->right = deleteNode(node->right, temp->data); // Delete the successor
    }

    return node;
}

    bool search(Node *node, int val)
    {
        if(node == nullptr) return false;
        if(node->data == val) return true;
        if(val<node->data)
        {
            return search(node->left,val);
        }
        else
            return search(node->right,val);
    }


 void inorder(Node *node)
{
//base case needed
    if(node== nullptr)
    {
        return;
    }

        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
}




void preorder(Node *node)
{//base case needed

    if(node== nullptr)
    {
        return;
    }
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
}
void postorder(Node *node)
{

    if(node== nullptr)
    {
        return;
    }
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
}


int main()
{
    Node *node =nullptr;


    cout << "Enter tree elements separated by space (type -1 to stop): ";

    int num;
    while (cin >> num && num != -1) { // Read input until -1 is entered
        node = insertNode(node, num);
    }
    cout<<"Inorder Traversal: ";
            inorder(node);
            cout<<endl;
            cout<<"Preorder Traversal: ";
            preorder(node);
            cout<<endl;
            cout<<"Postorder Traversal: ";
            postorder(node);
            cout<<endl;
    int choice, value;

    do{
        cout<<"\n-----Menu---\n";
        cout<<"1. Insert Element\n";
        cout<<"2. Delete Element\n";
        cout<<"3. Search Element\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"enter the value to insert: ";
            cin>>value;
            node = insertNode(node, value);
            system("cls");
            cout<<"Inorder Traversal: ";
            inorder(node);
            cout<<endl;
            cout<<"Preorder Traversal: ";
            preorder(node);
            cout<<endl;
            cout<<"Postorder Traversal: ";
            postorder(node);
            cout<<endl;
            break;

        case 2:
            cout<<"enter the value to delete: ";
            cin>>value;
            node = deleteNode(node, value);
            system("cls");
            cout<<"Inorder Traversal: ";
            inorder(node);
            cout<<endl;
            cout<<"Preorder Traversal: ";
            preorder(node);
            cout<<endl;
            cout<<"Postorder Traversal: ";
            postorder(node);
            cout<<endl;

            break;
        case 3:
            cout<<"enter the value to search: ";
            cin>>value;

            system("cls");
            cout<<"Inorder Traversal: ";
            inorder(node);
            cout<<endl;
            cout<<"Preorder Traversal: ";
            preorder(node);
            cout<<endl;
            cout<<"Postorder Traversal: ";
            postorder(node);
            cout<<endl;
            if(search(node, value))
            {
                cout<<"Found in BST";
            }
            else{cout<<"Not found in BST";}
            break;
        case 4:
            cout<<"Exiting program......";
            break;
        default:
            cout<<"Invalid choice. Please try again.\n";
        }
    }
    while(choice!=4);

    return 0;

}