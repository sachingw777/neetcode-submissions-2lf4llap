#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c: s){
            if(mp.count(c)){
                if(!stck.empty() && stck.top() == mp[c]) stck.pop();
                else return false;
            }else{
                stck.push(c);
            }
        }

        return stck.empty();
    }
};
