class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer>[] freq = new List[nums.length + 1];

        for(int n: nums){
            mp.put(n, mp.getOrDefault(n, 0) + 1);
        }

        for(int i = 0; i < freq.length; i++){
            freq[i] = new ArrayList<>();
        }

        for(Map.Entry<Integer, Integer> e: mp.entrySet()){
            freq[e.getValue()].add(e.getKey());
        }

        int index = 0;
        int[] res = new int[k];
        for(int i = freq.length - 1; i > 0 && index < k; i--){
            for(int n: freq[i]){
                res[index] = n;
                index++;

                if(index == k) return res;
            }
        }

        return res;
    }
}
