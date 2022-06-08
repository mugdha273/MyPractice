class Solution {
public:
    bool check(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    vector<vector<string>>ans;
    
    void helper(int idx, string s, vector<string>&sub)
    {
        if(idx==s.length())
        {
            ans.push_back(sub);
        }
        
        for(int i=idx; i<s.length();i++)
        {
            if(check(s,idx,i))
            {
                sub.push_back(s.substr(idx, i - idx + 1));
                helper(i+1,s,sub);
                sub.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> emp;
        helper(0,s,emp);
        return ans;
    }
};