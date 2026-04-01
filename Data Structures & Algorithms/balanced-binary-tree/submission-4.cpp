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
        bool balanced;
    };

    Pair helper(TreeNode* root) {
        if (root == NULL) return {0, true};

        Pair left = helper(root->left);
        Pair right = helper(root->right);

        int height = max(left.height, right.height) + 1;
        bool balanced = left.balanced && right.balanced && abs(left.height - right.height) <= 1;

        return {height, balanced};
    }

    bool isBalanced(TreeNode* root) {
        return helper(root).balanced;
    }

};
