class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;
        subsetHelper(nums, ans, allSubsets, 0);
        return allSubsets;
    }

    void subsetHelper(vector<int>& nums, vector<int>& ans, vector<vector<int>> &allSubsets, int i){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        subsetHelper(nums, ans, allSubsets, i+1);

        ans.pop_back();
        subsetHelper(nums, ans, allSubsets, i+1);
    }
};
