class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, maxFreq = 0, maxLength = 0;
        unordered_map<char,int> countChar;

        for(int end = 0; end < s.size(); end++){
            countChar[s[end]]++;
            maxFreq = max(maxFreq, countChar[s[end]]);

            while((end-start+1) - maxFreq > k){
                countChar[s[start]]--;
                start++;
            }
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
};
