class Solution {
private:
    
    map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    
    vector<string>result;
    
    public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0)return result;
        
        generateCombinations("", digits,0);
        
        return result;
    }
    
    void generateCombinations(string curr, string digits, int index)
    {
        if(index== digits.size())result.push_back(curr);
        
        else
        {
            char currD = digits[index];
            string mapping = m[currD];
            
            for(int i=0; i<mapping.size(); i++)
                generateCombinations(curr+ mapping[i], digits, index+1);
        }
        
    }
    
    
    
};