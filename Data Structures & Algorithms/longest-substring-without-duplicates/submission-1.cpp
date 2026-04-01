class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if(size == 0 || size == 1) return size;

        unordered_set<char> set;
        int l = 0, r = 0, maxLength = 0;

        while(r < size){
            while(set.count(s[r])){
                set.erase(s[l]);
                l++;
            }

            set.insert(s[r]);
            maxLength = max(maxLength, r-l+1);
            r++;
        }

        return maxLength;
    }
};
