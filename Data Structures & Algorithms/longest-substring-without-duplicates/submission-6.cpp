class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLength = 0;
        unordered_map<char,int> state;

        for(int end = 0; end < s.size(); end++){
            if(state.find(s[end]) != state.end()){
                start = max(start, state[s[end]]+1);
            }

            state[s[end]] = end;
            maxLength = max(maxLength, end-start+1);
        }

        return maxLength;
    }
};
