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

#include<queue>
class Solution {
public:
    // vector<int> rightSideView(TreeNode* root) {
    //     if(root == NULL) return {};

    //     vector<int> answer;
    //     queue<TreeNode*> q;
    //     q.push(root);1
    //     q.push(NULL);

    //     TreeNode* prev = NULL;
    //     while(q.size()){
    //         TreeNode* front = q.front();
    //         q.pop();

    //         if(front && front->left) q.push(front->left);
    //         if(front && front->right) q.push(front->right);

    //         if(front == NULL){
    //             answer.push_back(prev->val);
    //             if(q.size()) q.push(NULL);
    //         }

    //         prev = front;
    //     }

    //     return answer;
    // }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;

        if(level == ans.size()){
            ans.push_back(root->val);
        }

        dfs(root->right, level+1, ans);
        dfs(root->left, level+1, ans);
    }
};
