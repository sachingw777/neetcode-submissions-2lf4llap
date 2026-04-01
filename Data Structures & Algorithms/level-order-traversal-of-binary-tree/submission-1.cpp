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
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if(root == NULL) return {};

    //     vector<vector<int>> master;
    //     vector<int> answer;
    //     queue<TreeNode*> q;
        
    //     q.push(root);
    //     q.push(NULL);

    //     while(q.size()){
    //         TreeNode* front = q.front();
    //         q.pop();

    //         if(front){
    //             answer.push_back(front->val);
    //             if(front->left) q.push(front->left);
    //             if(front->right) q.push(front->right);
    //         }else{
    //             if(q.size()) q.push(NULL);
    //             master.push_back(answer);
    //             answer = {};
    //         }
    //     }

    //     return master;
    // }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> master;
        dfs(root, 0, master);
        return master;
    }

    void dfs(TreeNode* node, int level, vector<vector<int>>& master){
        if(!node) return;

        if(level == master.size()){
            master.push_back({});
        }

        master[level].push_back(node->val);
        dfs(node->left, level+1, master);
        dfs(node->right, level+1, master);
    }

};
