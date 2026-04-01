class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        
        unordered_map<char, int> tMap, window;
        for(char c: t){
            tMap[c]++;
        }

        int have = 0, need = tMap.size(), resLength = INT_MAX, l = 0;
        pair<int,int> res = {-1, -1};

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;

            if(tMap.count(c) && window[c] == tMap[c]) have++;

            while(have == need){
                if(r-l+1 < resLength){
                    resLength = r-l+1;
                    res = {l, r};
                }

                window[s[l]]--;
                if(window[s[l]] < tMap[s[l]] && tMap.count(s[l])) have--;

                l++;
            }
        }

        return resLength == INT_MAX ? "" : s.substr(res.first, resLength);
    }
};
