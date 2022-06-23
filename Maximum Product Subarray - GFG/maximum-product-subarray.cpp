// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	  
        long long int res = arr[0], l = 0, r = 0;
        
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * arr[i];
            r =  (r ? r : 1) * arr[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends