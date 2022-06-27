class Solution {
public:
    //very clever question
    int minPartitions(string s) {
        int n = s.length();
        int ans=0;
        
        for(auto x:s) ans=max(ans,x-'0');
        
        return ans;
    }
};