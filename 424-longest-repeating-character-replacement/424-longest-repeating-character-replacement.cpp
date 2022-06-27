class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.length();
        map<char,int>mp;
        int maxChar=0;
        // AABABBA;
        int window_length=0;
        int ans{0}, curr{0};
        
        int i{0}, j{0};
        
        while(j<n)
        {
            mp[s[j]]++;
            maxChar= max(mp[s[j]],maxChar);
            window_length= j-i+1;
            curr= window_length-maxChar;
            
            if(curr>k)
            {
                mp[s[i]]--;
                 i++;
            }
            ans= max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};