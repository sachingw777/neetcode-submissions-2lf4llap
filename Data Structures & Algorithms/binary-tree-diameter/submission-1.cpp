/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    struct Pair {
        int height;
        int diameter;
    };

    Pair helper(TreeNode* root) {
        if (root == NULL) return {0, 0};

        Pair left = helper(root->left);
        Pair right = helper(root->right);

        // height = max height of children + 1
        int height = max(left.height, right.height) + 1;

        // diameter = max of (left diameter, right diameter, path through root)
        int diameter = max({left.diameter, right.diameter, left.height + right.height});

        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).diameter;
    }

};
