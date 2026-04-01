class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const string& c: tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();

                if(c == "+") s.push(b+a);
                else if(c == "-") s.push(b-a);
                else if(c == "*") s.push(b*a);
                else if(c == "/") s.push(b/a);
            }else{
                s.push(stoi(c));
            }
        }

        return s.top();
    }
};
