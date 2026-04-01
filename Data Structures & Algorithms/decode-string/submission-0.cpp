class Solution {
public:
 string decodeString(string s) {
        stack<char> stck;

        for(char c : s){
            if(c != ']'){
                stck.push(c);
            } else {
                // 1. build substring
                string small = "";
                while(!stck.empty() && stck.top() != '['){
                    small = stck.top() + small;
                    stck.pop();
                }

                // pop '['
                stck.pop();

                // 2. get number
                int val = 0, multiplier = 1;
                while(!stck.empty() && isdigit(stck.top())){
                    val += (stck.top() - '0') * multiplier;
                    multiplier *= 10;
                    stck.pop();
                }

                // 3. repeat and push back
                string expanded = "";
                for(int i = 0; i < val; i++){
                    expanded += small;
                }

                for(char ch : expanded){
                    stck.push(ch);
                }
            }
        }

        // 4. build final answer
        string answer = "";
        while(!stck.empty()){
            answer = stck.top() + answer;
            stck.pop();
        }

        return answer;
    }
}; 