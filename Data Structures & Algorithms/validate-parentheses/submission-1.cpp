#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                stck.push(s[i]);
            }else{
                if(stck.empty()) return false;

                char topEl = stck.top();
                stck.pop();

                if(topEl == '{' && s[i] == '}') continue;
                else if(topEl == '[' && s[i] == ']') continue;
                else if(topEl == '(' && s[i] == ')') continue;
                
                return false;
            }
        }

        if(stck.empty()) return true;
        
        return false;
    }
};
