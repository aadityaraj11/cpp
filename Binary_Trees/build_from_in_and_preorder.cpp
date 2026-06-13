#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Utility function to create a new tree node
TreeNode* newNode(int data) {
    return new TreeNode(data);
}

// Recursive function to construct binary tree from inorder and preorder
TreeNode* buildTreeHelper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
    if (preStart >= preorder.size() || inStart > inEnd)
        return NULL;

    // Create the root node
    TreeNode* root = newNode(preorder[preStart]);

    // Find the index of the root in the inorder traversal
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    // Recurse on left and right subtrees
    root->left = buildTreeHelper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
    root->right = buildTreeHelper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);

    return root;
}

// Wrapper function to construct binary tree
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeHelper(0, 0, inorder.size() - 1, preorder, inorder);
}

// Inorder traversal for testing
void inorderTraversal(TreeNode* root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Example input:
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    vector<int> inorder = {4, 2, 5, 1, 3, 6};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory (optional)
    // ...

    return 0;
}
