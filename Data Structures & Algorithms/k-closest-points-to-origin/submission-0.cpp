class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        for(auto el: points){
            int dist = el[0]*el[0] + el[1]*el[1];
            maxHeap.push({dist, {el[0], el[1]}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        } //creates heap
        vector<vector<int>> answer;
        while(!maxHeap.empty()){
            auto point = maxHeap.top().second;
            answer.push_back({point.first, point.second});
            maxHeap.pop();
        }

        return answer;

    }
};
