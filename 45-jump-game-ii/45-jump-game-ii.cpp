class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, r=0;
        int n= nums.size();
        int cnt=0;
        
        while(r<n-1)
        {
            int maxR=0;
            for(int i=l; i<=r; i++)
            {
                maxR= max(nums[i]+i, maxR);
            }
            cnt++;
            l=r+1;
            r=maxR;
        }
        
        return cnt;
    }
};