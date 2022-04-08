class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0, n= s.length();
        map<int, int>mp;
        
        int ans=0;
        
        while(j<n)
        {
            mp[s[j]]++;
            
            if(mp[s[j]] == 1)
            {
                ans = max(ans, j-i+1);
                
            }
            else
            {
                while(mp[s[j]] != 1){
                    mp[s[i]]--;
                    i++;
                }
            }
            j++;
            
            
        }
        
        return ans;
        
    }
};