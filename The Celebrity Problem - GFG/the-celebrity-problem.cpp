// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        vector<int>in(n,0);
        vector<int>out(n,0);
        for(int i=0; i<m.size(); i++)
        {
            for(int j=0; j<m[i].size(); j++)
            {
                in[j]+= m[i][j];
                out[i]+=m[i][j];
            }
        }
        
        for(int i=0; i<n; i++)
        if(in[i] == n-1 && out[i] == 0)
            return i;
        
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends