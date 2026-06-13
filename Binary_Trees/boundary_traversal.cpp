#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Utility function to create a new tree node
TreeNode* newNode(int data) {
    return new TreeNode(data);
}

// Print the left boundary (top-down)
void printLeftBoundary(TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return;

    cout << root->data << " ";

    if (root->left)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

// Print the leaf nodes
void printLeaves(TreeNode* root) {
    if (!root)
        return;

    if (!root->left && !root->right)
        cout << root->data << " ";

    printLeaves(root->left);
    printLeaves(root->right);
}

// Print the right boundary (bottom-up)
void printRightBoundary(TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);

    cout << root->data << " ";
}

// Perform boundary traversal
void printBoundary(TreeNode* root) {
    if (!root)
        return;

    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
}

int main() {
    // Construct a sample binary tree
    TreeNode* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right->right = newNode(25);

    // Perform boundary traversal
    printBoundary(root);

    return 0;
}
 