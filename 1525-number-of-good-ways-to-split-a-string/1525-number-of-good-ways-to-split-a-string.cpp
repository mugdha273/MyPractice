class Solution {
public:
    int numSplits(string s) {
        map<char,int>mp1;
        map<char,int>mp2;
        for(auto x:s)mp2[x]++;

        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            mp2[s[i]]--;
            
            if(mp2[s[i]]==0) mp2.erase(s[i]);
            mp1[s[i]]++;
            if(mp1.size()==mp2.size()) ans++;
        }
        
        return ans;
    }
};