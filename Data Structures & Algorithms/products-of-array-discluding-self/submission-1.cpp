class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                prefix[i] = 1;
                continue;
            }
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        int postFix = 1;
        for(int j = prefix.size()-2; j >= 0; j--){
            postFix *= nums[j+1];
            prefix[j] *= postFix;
        }

        return prefix;
    }
};
