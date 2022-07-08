class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>vec(n+1);
        if(n==0) return 0;
        if(n==1) return 1;
        vec[0]=0;
        vec[1]=1;
        int i=0;
        int ans=INT_MIN;
        
        while(2*i+1<=n)
        {
            vec[2*i]=vec[i];
            ans= max(ans,vec[2*i]);
            vec[2*i+1]= vec[i]+vec[i+1];
            ans= max(ans,vec[2*i+1]);
            i++;
        }
        // for(auto x:vec)cout<<x<<" ";
        return ans;
    }
};