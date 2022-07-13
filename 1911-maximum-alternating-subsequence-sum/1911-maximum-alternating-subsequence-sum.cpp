class Solution {
public:
    //Mahhhn! I'm so proud! I wrote the recursive solution all by myself in one go.
    long long dp[100000][2];
    vector<int> a;
    int n;
    long long helper(int i, int state)
    {
        if(i>=n)
        {
            return 0;
        }
        long long ans=INT_MIN;
        if(dp[i][state]!=-1) return dp[i][state];

        if(state==0){
            ans=max(helper(i+1,1)+a[i],helper(i+1,0));
        }
        else if(state==1){
            ans=max(helper(i+1,0)-a[i],helper(i+1,1));
        }
        return dp[i][state]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        a=nums;
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,0);
    }
};