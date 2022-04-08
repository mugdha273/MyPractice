class Solution {
public:
    string helper(string a, string b)
    {
        if(a.size()>b.size()) return helper(b,a);
        
        int x = a.size();
        int y = b.size();
        string s="";
        for(int i=0; i<x; i++)
        {
           if(a[i]==b[i]) s+=a[i];
           else break; 
        }
        
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()== 1) return strs[0];
        
        string s = helper(strs[0],strs[1]);
        
        for(int i=2; i<strs.size(); i++)
        {
            s= helper(s, strs[i]);
        }
        
        return s;
    }
};