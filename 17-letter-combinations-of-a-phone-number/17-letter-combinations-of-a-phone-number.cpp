class Solution {
public:
    map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    
    vector<string>result;
    
    void helper(int i, string s, string digits)
    {
        if(s.length()==digits.size())
        {
            result.push_back(s);
            return;
        }
        string mapping = m[digits[i]];
        
        for(int p= 0; p<mapping.size();p++)
        {
            helper(i+1,s+mapping[p],digits);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return result;
        
        helper(0,"", digits);
        
        return result;
    }
};