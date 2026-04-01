class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        int i = 0;

        while(i < nums.size()-2){
            if(nums[i] > 0) break;
            while(i > 0 && nums[i] == nums[i-1]) i++;

            int j = i+1, k = nums.size()-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    answer.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;

                    while(nums[j] == nums[j-1]) j++;
                    while(nums[k] == nums[k+1]) k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
            i++;
        }

        return answer;
    }
};
