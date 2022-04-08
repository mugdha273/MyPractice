// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans=0;
    void mergeSort(long long nums[], long long l, long long r)
    {
        if(l<r)
        {
            long long mid = (l+r)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums,mid+1, r);
            
            merge(nums, l, mid, r);
        }
        
    }
    
    int merge(long long nums[], long long l, long long mid, long long r)
    {
        long long n1 = mid-l+1;
        long long n2 = r - mid;
        
        long long v1[n1];
        long long v2[n2];
        
        for(int i=0; i<n1; i++)
        {
            v1[i]= nums[l+i];
        }
        
        for(int i=0; i<n2; i++)
        {
            v2[i] = nums[mid+1+i];
        }
        
        int i=0, j=0, k=l;
        
        while(i<n1 && j<n2)
        {
            if(v1[i]<= v2[j])
            {
                nums[k++]= v1[i++];
            }
            else
            {
                nums[k++] = v2[j++];
                ans += (n1 - i);
            }
        }
        
        while(i<n1)
        {
            nums[k++]= v1[i++];
        }
        while(j<n2)
        {
            nums[k++]= v2[j++];
        }
        
        return ans;
    }
    

long long int inversionCount(long long arr[], long long n)
{
    // Your Code He
     mergeSort(arr, 0, n-1);
     return ans;
}

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends