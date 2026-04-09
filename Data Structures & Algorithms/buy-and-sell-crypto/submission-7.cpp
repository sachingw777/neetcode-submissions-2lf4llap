class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = prices[0], maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < sell){
                sell = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i]-sell);
            }
        }

        return maxProfit;
    }
};
