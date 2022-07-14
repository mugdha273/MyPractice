class Solution {
public:
    int maxAbsoluteSum(vector<int>&v) {
        int ans=0;
        int sum=0;
        int i,n=v.size();

        for (i=0; i<n; i++){
            sum+=v[i];
            
            ans=max(ans,sum);
            if (sum<0){
                sum=0;
            }
        }

        sum=0;
        for (i=0; i<n; i++){
            sum+=(-v[i]);
            
            ans=max(ans,sum);
            if (sum<0){
                sum=0;
            }
        }
        
     return ans;
    }
};