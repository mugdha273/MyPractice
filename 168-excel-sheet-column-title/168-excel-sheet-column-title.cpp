class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        
        while(columnNumber--)
        {
            int p= columnNumber%26;
            ans+= p+'A';
            columnNumber/=26;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};