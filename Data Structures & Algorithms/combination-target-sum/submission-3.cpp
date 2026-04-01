class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        // vector<int> curr;
        // backtrack(nums, target, res, curr, 0);
        sort(nums.begin(), nums.end());
        dfs(res, nums, target, {}, 0, 0);
        return res;
    }

    // void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& curr, int i){
    //     if(target == 0){
    //         res.push_back(curr);
    //         return;
    //     }

    //     if(i >= nums.size() || target < 0){
    //         return;
    //     }

    //     curr.push_back(nums[i]);
    //     backtrack(nums, target-nums[i], res, curr, i);
    //     curr.pop_back();
    //     backtrack(nums, target, res, curr, i+1);
    // }

    void dfs(vector<vector<int>>& res, vector<int>& nums, int target, vector<int> curr, int total, int i){
        if(total == target){
            res.push_back(curr);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            if(total + nums[j] > target) return;

            curr.push_back(nums[j]);
            dfs(res, nums, target, curr, total+nums[j], j);
            curr.pop_back();
        }
    }
};
