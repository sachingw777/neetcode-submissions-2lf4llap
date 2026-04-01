class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c - 'a']++;
            }

            string code = "#";
            for(int i = 0; i < 26; i++){
                code = code + to_string(count[i]) + "#";
            } //hash is complete here

            mp[code].push_back(s);
        }

        vector<vector<string>> result;
        for(auto [first, second]: mp){
            result.push_back(second);
        }

        return result;
    }
};
