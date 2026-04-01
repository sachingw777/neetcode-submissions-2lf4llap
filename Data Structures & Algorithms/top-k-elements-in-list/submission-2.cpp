class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n: nums){
            mp[n]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto& [first, second]: mp){
            bucket[second].push_back(first);
        }

        vector<int> answer;
        for(int i = bucket.size()-1; i > 0; i--){
            if(bucket[i].size() == 0) continue;
            for(auto d: bucket[i]){
                if(answer.size() >= k) break;
                answer.push_back(d);
            }
        }

        return answer;
    }
};
