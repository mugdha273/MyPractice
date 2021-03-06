// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool check(int arr[], int n, int sum)
    {
        if(n==0 && sum==0) return 1;
        if(n==0 && sum!=0) return 0;
        if(arr[n-1]>sum) return check(arr,n-1,sum);
        
        return check(arr,n-1, sum-arr[n-1])|| check(arr,n-1,sum);
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        
        if(check(arr,N,sum/2)) return 1;
        
        return 0;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends