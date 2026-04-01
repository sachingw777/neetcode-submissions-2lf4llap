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
    int helper(TreeNode* root, int maxSoFar){
        if(!root) return 0;

        int good = 0;
        if(root->val >= maxSoFar){
            good++;
            maxSoFar = root->val;
        }

        return good+ helper(root->left, maxSoFar) + helper(root->right, maxSoFar);
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
