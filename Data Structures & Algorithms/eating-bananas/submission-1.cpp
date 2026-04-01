class Solution {
public:
    int timeTaken(vector<int>& piles, int rate){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += (piles[i] + rate - 1)/rate;
        }
        
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = l + (r-l)/2;
            int timeCalculation = timeTaken(piles, mid);

            if(timeCalculation > h){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
