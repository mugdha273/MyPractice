// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int jump=0;
        int far=0;
        int reach=0;
        
        for(int i=0; i<n-1; i++)
        {
            far = max(i+arr[i], far);
            
            if(i==reach)
            {
                jump++;
                if(reach==far) return -1;
                reach=far;
                if(reach>= n-1)break;
            }
        }
        
        return jump;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends