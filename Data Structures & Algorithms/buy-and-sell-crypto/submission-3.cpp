class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = i+1, mp = 0, size = prices.size();

        while(j < size && i != j){
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
};
