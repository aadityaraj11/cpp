#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive function to find the LCA
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (!root)
        return NULL;

    // If either n1 or n2 matches the root value, root is the LCA
    if (root->val == n1 || root->val == n2)
        return root;

    // Recurse on left and right subtrees
    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);

    // If both leftLCA and rightLCA are non-null, root is the LCA
    if (leftLCA && rightLCA)
        return root;

    // Otherwise, return the non-null LCA (if any)
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    // Construct a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int n1 = 4, n2 = 5;
    TreeNode* lca = findLCA(root, n1, n2);
    if (lca)
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    else
        cout << "One or both nodes not found in the tree." << endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
