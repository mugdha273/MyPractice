class Solution {
public:
    
    void dfs(vector<vector<int>>&adj, vector<int>&vis, int node)
    {
        vis[node]=1;
        
        for(auto x: adj[node])
        {
            if(!vis[x])
            {
                // vis[x]=1;
                dfs(adj,vis,x);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        
        vector<vector<int>>adj(n);
        vector<int>vis(n+1,0);
        int ans=0;
        
        for(auto x: connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) {
                ans++;
                dfs(adj,vis,i);
            }
        }
            
        return ans-1;
    }
};