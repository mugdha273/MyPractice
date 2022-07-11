class Solution {
public:
    int ans;
    void solve(vector<int> &c,int i,vector<int> &b){
        int k=b.size();
        if(i==c.size()){
            int mx=INT_MIN;
            for(int j=0;j<k;j++){
                mx=max(b[j],mx);
            }
        //     for(auto x:b)cout<<x<<" ";
        // cout<<endl;
            ans=min(ans,mx);
            return;
        }
        
        for(int j=0;j<k;j++){
            b[j]+=c[i];
            solve(c,i+1,b);
            b[j]-=c[i];
        }
        
    }
    int distributeCookies(vector<int>& c, int k) {
        
        vector<int> bags(k,0);
        ans=INT_MAX;
        
        solve(c,0,bags);
        return ans;
    }
};