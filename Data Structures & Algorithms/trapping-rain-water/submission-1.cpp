class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size == 0) return 0;

        vector<int> maxLeft(size), maxRight(size);
        maxLeft[0] = height[0], maxRight[size-1] = height[size-1];

        for(int i = 1; i < size; i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }
        
        for(int i = size-2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        int res = 0;
        for(int i = 0; i < size; i++){
            int val = min(maxLeft[i], maxRight[i]) - height[i];
            if(val > 0){
                res += val;
            }
        }

        return res;
    }
};
