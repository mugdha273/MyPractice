class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int>mp;
        int n =s.size();
        
        if(n==0) return 0;
        
        int i=0,j=0;
        int ans= 0;
        
        while(j<n)
        {
            
           mp[s[j]]++;
           if(mp[s[j]]==1)
            {
                ans= max(ans, j-i+1);
             }
            else
            {
                while(mp[s[j]]!=1 && i<=j)
                {
                   
                    mp[s[i]]--;
                    i++;
                }
            }
            j++;
                
        }
        
        
        return ans;
    }
};