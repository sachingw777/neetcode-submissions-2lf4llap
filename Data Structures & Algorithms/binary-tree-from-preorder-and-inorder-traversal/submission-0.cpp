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

    int preIndex = 0;
    unordered_map<int,int> inorderIndex;

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];

        root->left = helper(preorder, inorder, left, mid-1); 
        root->right = helper(preorder, inorder, mid+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }

        return helper(preorder, inorder, 0, inorder.size()-1);
    }
};
