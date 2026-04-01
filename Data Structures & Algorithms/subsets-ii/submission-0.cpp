class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        vector<vector<int>> allSubsets;

        helper(nums, ans, allSubsets, 0);
        return allSubsets;
    }

    void helper(vector<int>& nums, vector<int>& ans, vector<vector<int>>& allSubsets, int i){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        helper(nums, ans, allSubsets, i+1);

        ans.pop_back();
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        helper(nums, ans, allSubsets, idx);
    }
};
