class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0) return 0;
        priority_queue<int> maxHeap;

        for(int stone: stones){
            maxHeap.push(stone);
        } //heap is created

        while(maxHeap.size() > 1){
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();

            if(b < a){
                maxHeap.push(a-b);
            }
        }
        
        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};
