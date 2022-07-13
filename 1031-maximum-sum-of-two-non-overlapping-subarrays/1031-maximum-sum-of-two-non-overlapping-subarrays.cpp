class Solution {
public:
    int helper(vector<int>& nums,int f, int s)
    {
        int n= nums.size();
        vector<int>dp1(n+1,0);
        vector<int>dp2(n+1,0);
        
        int sum=0;
        for(int i = 0; i < n; i++)
        {
            if(i <f)
            {
                sum += nums[i];
                
                dp1[i] = sum;
            }
            else if(i >=f)
            {
                sum += nums[i] - nums[i - f];
                
                dp1[i] = max(dp1[i - 1], sum);
            }
        }
        sum = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(i >= n - s)
            {
                sum += nums[i];
                
                dp2[i] = sum;
            }
            else
            {
                sum += nums[i] - nums[i + s];
                
                dp2[i] = max(dp2[i + 1], sum);
            }
        }
        int ans = INT_MIN;
        
        for(int i = f - 1; i < n - s; i++)
        {
            ans = max(ans, dp1[i] + dp2[i + 1]);
        }
        
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n= nums.size();
        int a= helper(nums,f,s);
        int b= helper(nums,s,f);
        return max(a,b);
    }
};