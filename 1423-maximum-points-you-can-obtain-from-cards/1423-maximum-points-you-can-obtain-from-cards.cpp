class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        
        vector<int> f(n+1, 0);
        vector<int> b(n+1, 0);
        
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
            f[i+1] = sum;
        }
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += cardPoints[i];
            b[i] = sum;
        }
        
        reverse(b.begin(), b.end());
        int ans=0;
        
        for (int i=0; i<=k; i++) {
            ans= max(ans, f[i]+b[k-i]);
        }
        
        return ans;
    }
};