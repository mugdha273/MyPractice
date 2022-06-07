class Solution {
public:
    vector<string>ans;
    
    void helper(int n, string &s, int o, int c)
    {
        if(o==c && o==n)
        {
            ans.push_back(s);
            return;
        }
        
        if(o<n)
        {
            s.push_back('(');
            helper(n,s,o+1,c);
            s.pop_back();
        }
        if(c<o)
        {
            s.push_back(')');
            helper(n,s,o,c+1);
            s.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        helper(n,s,0,0);
        return ans;
    }
};