class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = prices[0], maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int current = prices[i];
            if(sell > current){
                sell = current;
                continue;
            }

            int profit = current - sell;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
