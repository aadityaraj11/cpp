#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive function to find the k-th ancestor
TreeNode* kthAncestor(TreeNode* root, int k, int targetNode) {
    if (!root)
        return NULL;

    if (root->val == targetNode)
        return root;

    TreeNode* leftAncestor = kthAncestor(root->left, k, targetNode);
    TreeNode* rightAncestor = kthAncestor(root->right, k, targetNode);

    if (leftAncestor || rightAncestor) {
        if (k > 0)
            k--;
        else if (k == 0)
            return root;
        return leftAncestor ? leftAncestor : rightAncestor;
    }

    return NULL;
}

int main() {
    /*
    Construct a sample binary tree:
          1
         / \
        2   3
       / \
      4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int k = 2; // K value
    int targetNode = 5; // Node for which we want to find the k-th ancestor

    TreeNode* ancestor = kthAncestor(root, k, targetNode);
    if (ancestor)
        cout << "K-th ancestor of node " << targetNode << " is: " << ancestor->val << endl;
    else
        cout << "No such ancestor exists." << endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
