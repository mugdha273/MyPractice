class Solution {
public:
    string longestPalindrome(string a) {
    int n= a.length();
    int mid=n-1;
    int ans=0;
    int currA;
    
    string finalS= "";
    
    while(mid>=0)
    {
        
        int midB= mid;
        int midE= mid+1;
        
        while(midE<n && midB>=0 && a[midB]== a[midE])
        {

            currA= midE-midB+1;
            if(currA>=ans)
            {
                finalS = a.substr(midB,midE-midB+1);
                ans= midE-midB+1;
            }
            midE++;
            midB--;
            
        }
        
        currA=0;
        midB= mid;
        midE= mid;
        
        while(midE<n && midB>=0 && a[midB]== a[midE])
        {
            currA= midE-midB+1;
            if(currA>=ans)
            {
                finalS = a.substr(midB,midE-midB+1);
                ans= midE-midB+1;
            }
            midE++;
            midB--;
            
        }
        
        mid--;
    }
        return finalS;
    }
};