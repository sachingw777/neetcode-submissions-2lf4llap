#include<string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i = 0; i < strs.size(); i++){
            res += to_string(strs[i].size()) + "#" + strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j-i));
            string word = s.substr(j+1, length);
            res.push_back(word);
            i = j + length + 1;
        }

        return res;
    }
};
