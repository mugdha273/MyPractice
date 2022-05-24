// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int N)  { 
	    // Your code goes here
        int sum=0;
        for (int i = 0; i <N; i++)
        sum += nums[i];
        
        int dp[N+1][sum+1];
        for (int i = 0; i <= N; i++)
        dp[i][0] = true;
 
        for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
        
        for(int i=1;i<=N;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               
               if (j < nums[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1])
                dp[i][j] = dp[i - 1][j]
                               || dp[i - 1][j - nums[i - 1]];
               
           }
       }
       
        int diff = INT_MAX;

        for (int j = sum / 2; j >= 0; j--) {
            if (dp[N][j] == true) {
                diff = min(diff, sum - 2 * j);
            }
        }
        return diff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends