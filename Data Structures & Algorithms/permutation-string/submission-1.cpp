class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        unordered_map<char,int> need, window;

        for(char c: s1) need[c]++;

        int start = 0, k = s1.size();
        for(int end = 0; end < s2.size(); end++){
            window[s2[end]]++;

            if(end-start+1 == k){
                if(window == need) return true;

                window[s2[start]]--;
                if(window[s2[start]] == 0) window.erase(s2[start]);
                start++;
            }
        }
        
        return false;
    }
};