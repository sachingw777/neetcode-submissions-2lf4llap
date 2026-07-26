class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0 || nums == null) return 0;

        Set<Integer> s = new HashSet<>();
        for(int n: nums) s.add(n);

        int maxStreak = 0;
        for(int n: nums){
            if(s.contains(n-1)) continue;
            
            int temp = n, streak = 1;
            while(s.contains(temp+1)){
                streak++;
                temp++;
            }
            maxStreak = Math.max(streak, maxStreak);
        }

        return maxStreak;
    }
}
