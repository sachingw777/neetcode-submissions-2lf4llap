class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLength = 0;
        unordered_set<char> state;

        for(int end = 0; end < s.size(); end++){
            while(state.find(s[end]) != state.end()){
                state.erase(s[start]);
                start++;
            }

            state.insert(s[end]);
            maxLength = max(maxLength, end-start+1);
        }

        return maxLength;
    }
};
