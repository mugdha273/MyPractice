// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


    class Solution{
public:
bool isSafe(int i, int j, int m, int n)
{
    return (i>=0 && i<m && j>=0 && j<n);
}
bool isBorder(int i, int j, int m, int n)
{
    return (i==0 || j==0 || i==m-1 || j==n-1);
}
    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        queue<pair<int,int>> q;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (mat[i][j]=='O' && isBorder(i, j, m, n ))
                {
                    mat[i][j] = 'B';
                    q.push(make_pair(i, j));
                }
            }
        }
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        while (!q.empty())
        {
            auto it = q.front(); q.pop();
            for (int ind=0; ind<4; ind++)
            {
                int ii = it.first+di[ind];
                int jj = it.second+dj[ind];
                if (isSafe(ii, jj, m, n) && mat[ii][jj]=='O' && !isBorder(ii, jj, m, n))
                {
                    mat[ii][jj] = 'B';
                    q.push(make_pair(ii, jj));
                }
            }
        }
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
                else if (mat[i][j] == 'B')
                {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends