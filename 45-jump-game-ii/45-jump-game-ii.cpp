class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        int l=0, r=0;
        int ans=0;
        
        while(r<n-1)
        {   
            int reach=nums[l];
         
            for(int i=l;i<=r; i++)
            {
                reach= max(reach,i+nums[i]);
            }
         
            l=r+1;
            r=reach;
            ans++;
        }
        return ans;
    }
};