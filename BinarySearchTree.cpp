#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

bool searchNode(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;

    if (value < root->data)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    int n, value, searchValue;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "In-order Traversal: ";
    inorderTraversal(root);

    cout << "\nEnter a value to search: ";
    cin >> searchValue;

    if (searchNode(root, searchValue))
        cout << searchValue << " exists in the tree.\n";
    else
        cout << searchValue << " does not exist in the tree.\n";

    return 0;
}
