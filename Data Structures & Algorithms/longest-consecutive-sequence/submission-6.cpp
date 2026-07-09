class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxStreak = 0;

        for(int n: set){
            if(!set.count(n-1)){
                int num = n, streak = 0;
                while(set.count(num)){
                    streak++;
                    num++;
                }

                maxStreak = max(maxStreak, streak);
            }
        }

        return maxStreak;
    }
};
