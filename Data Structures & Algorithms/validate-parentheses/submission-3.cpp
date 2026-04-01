#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for(char c: s){
            if(c == '{' || c == '[' || c == '('){
                stck.push(c);
            }else{
                if(stck.empty()) return false;

                char topEl = stck.top();

                if(topEl == '{' && c == '}' || topEl == '[' && c == ']' || topEl == '(' && c == ')') stck.pop();
                else return false;
            }
        }

        return stck.empty();
    }
};
