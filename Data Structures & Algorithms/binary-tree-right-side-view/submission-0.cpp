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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> answer;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        TreeNode* prev = NULL;
        while(q.size()){
            TreeNode* front = q.front();
            q.pop();

            if(front && front->left) q.push(front->left);
            if(front && front->right) q.push(front->right);

            if(front == NULL){
                answer.push_back(prev->val);
                if(q.size()) q.push(NULL);
            }

            prev = front;
        }

        return answer;
    }
};
