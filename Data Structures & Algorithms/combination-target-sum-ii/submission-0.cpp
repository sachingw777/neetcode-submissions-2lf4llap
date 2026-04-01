class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;

        cs2(candidates, ans, combination, 0, target);
        return ans;
    }

    void cs2(vector<int>& nums, vector<vector<int>>& ans, vector<int>& combination, int i, int target){
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        if(i == nums.size() || target < 0) return;

        combination.push_back(nums[i]);
        cs2(nums, ans, combination, i+1, target-nums[i]);
        combination.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[i]) idx++;
        cs2(nums, ans, combination, idx, target);
    }
};
