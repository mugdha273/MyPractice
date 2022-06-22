// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void dfs(string s, int i, int j, vector<vector<int>>&m)
    {
        if(i<0||i>=m.size()||j<0||j>=m[0].size()||m[i][j]==0) return;
        
        if(i==m.size()-1 && j==m[0].size()-1)
        {
            ans.push_back(s);
            return;
        }
        
        m[i][j]=0;
        dfs(s+'D',i+1,j,m);
        dfs(s+'L',i,j-1,m);
        dfs(s+'R',i,j+1,m);
        dfs(s+'U',i-1,j,m);
        m[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        dfs(s,0,0,m);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends