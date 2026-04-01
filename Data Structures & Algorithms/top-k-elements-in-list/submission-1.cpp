class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n : nums) freq[n]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto& [num,count]: freq){
            bucket[count].push_back(num);
        }

        vector<int> result;
        for(int i = bucket.size()-1; i >= 0; i--){
            for(int n: bucket[i]){
                if(result.size() == k) return result;
                result.push_back(n);
            }
        }

        return result;
    }
};