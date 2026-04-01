class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;

        cs(nums, ans, combination, 0, target);
        return ans;
    }

    void cs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& combination, int i, int target){
        if(i == nums.size() || target < 0) return;

        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back({combination});
                s.insert(combination);
            }
            return;
        }

        combination.push_back(nums[i]);

        cs(nums, ans, combination, i+1, target - nums[i]); //single
        cs(nums, ans, combination, i, target - nums[i]); //multiple

        combination.pop_back();

        cs(nums, ans, combination, i+1, target); //exclusion
    }
};
 