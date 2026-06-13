#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> findDiameter(TreeNode* root) {
    if (!root) {
        // Base case: Empty tree
        return {0, 0};
    }

    // Recurse on left and right subtrees
    pair<int, int> leftSubtree = findDiameter(root->left);
    pair<int, int> rightSubtree = findDiameter(root->right);

    // Calculate height of current subtree
    int height = 1 + max(leftSubtree.first, rightSubtree.first);

    // Calculate diameter passing through current node
    int diameterThroughRoot = leftSubtree.first + rightSubtree.first;

    // Update overall diameter
    int overallDiameter = max(diameterThroughRoot,max(leftSubtree.second, rightSubtree.second));

    return {height, overallDiameter};
}

int diameterOfBinaryTree(TreeNode* root) {
    pair<int, int> result = findDiameter(root);
    return result.second;
}

int main() {
   /* 

    // Construct a simple binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the given tree: " << diameterOfBinaryTree(root) << endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
