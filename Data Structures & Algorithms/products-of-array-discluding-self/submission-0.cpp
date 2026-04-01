class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) {
                output[i] = 1;
                continue;
            }
            output[i] = nums[i-1] * output[i-1];
        }

        int postfix = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            postfix = postfix * nums[i+1];
            output[i] = output[i] * postfix;
        }

        return output;
    }
};
