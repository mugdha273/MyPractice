class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        int s=0;
        
        
        for(auto x:nums)
        {
            
            if(mp[k-x]>0)
            {
                s++;
                mp[k-x]--;
                
            }
            else
            {
                mp[x]++;
            }
            
        }
        
        return s;
    }
};