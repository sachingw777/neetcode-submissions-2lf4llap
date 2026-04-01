class Solution {
public:
    int maxProfitSliding(vector<int>& prices) {
        int i = 0, j = i+1, mp = 0, size = prices.size();

        while(i < j && j < size && i != j){
            if(prices[i] > prices[j]){
                i = j;
            }else if(prices[i] < prices[j]){
                int profit = prices[j] - prices[i];
                mp = max(profit,mp);
            }

            j++;
        }

        return mp;
    }

    int maxProfit(vector<int>& prices){
        int maxP = 0, minBuy = prices[0];

        for(int current: prices){
            int daysProfit = current-minBuy;
            maxP = max(maxP, daysProfit);
            minBuy = min(minBuy, current);
        }

        return maxP;
    }
};
