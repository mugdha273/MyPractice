// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
        // Complete the function
        int l=0;
       int r=n-1;
        
        while(l<=r)
        {
            int m=(l+r)/2;
            
            if(arr[m]== target) return arr[m];
            
            else if(arr[m]> target) r=m-1;
            
            else l=m+1;
            
        }
        if(abs(target-arr[l])> abs(target-arr[r]) && r>=0) return arr[r];
        else return arr[l];
    } 
};

// { Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}
  // } Driver Code Ends