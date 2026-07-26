class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        int prefix = 1;
        res[0] = 1;

        for(int i = 1; i < nums.length; i++){
            prefix *= nums[i-1];
            res[i] = prefix;
        }

        int postfix = 1;
        for(int i = nums.length-2; i >= 0; i--){
            postfix *= nums[i+1];
            res[i] = postfix * res[i];
        }

        return res;
    }
}  
