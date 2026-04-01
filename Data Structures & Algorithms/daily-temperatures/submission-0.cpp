class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<pair<int,int>> stack;

        for(int i = 0; i < temperatures.size(); i++){
            int currentTemp  = temperatures[i];
            while(!stack.empty() && currentTemp > stack.top().first){
                auto topEl = stack.top();
                stack.pop();
                result[topEl.second] = i - topEl.second;
            }

            stack.push({currentTemp,i});
        }

        return result;

    }
};
