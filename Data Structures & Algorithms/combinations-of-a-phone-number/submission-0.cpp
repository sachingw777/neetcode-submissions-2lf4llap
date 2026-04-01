class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};

        string current = "";
        backtrack(0, current, digits, res, keypad);
        return res;
    }

    void backtrack(int index, string& current, string& digits, vector<string>& res, vector<string>& keypad){
        if(current.size() == digits.size()){
            if(current.size()!=0)res.push_back(current);
            return;
        }

        string chars = keypad[digits[index] -  '0'];
        for(char c: chars){
            current.push_back(c);
            backtrack(index+1, current, digits, res, keypad);
            current.pop_back();
        }
    }
};
