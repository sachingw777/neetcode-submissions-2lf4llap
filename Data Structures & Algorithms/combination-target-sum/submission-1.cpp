class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, target, res, curr, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& curr, int i){
        if(i >= nums.size() || target < 0){
            return;
        }


        if(target == 0){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(nums, target-nums[i], res, curr, i);
        curr.pop_back();
        backtrack(nums, target, res, curr, i+1);
    }
};
