class Solution {
public:
    int ans=0;
    
    void helper(int midE, int midB, string s)
    {
        int n= s.length();
        
        while(midE<n && midB>=0 && s[midB]== s[midE])
        {
            ans++;
            midE++;
            midB--;
            
        }
        
    }
    
    int countSubstrings(string a) {
        int n= a.length();
        int mid=n-1;


        while(mid>=0)
        {
           helper(mid,mid,a);
           helper(mid+1, mid,a);
            mid--;
        }

        return ans;
    }
};