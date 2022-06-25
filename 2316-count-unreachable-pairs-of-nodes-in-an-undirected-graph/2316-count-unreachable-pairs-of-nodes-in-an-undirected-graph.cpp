class Solution {
public:
    typedef long long ll;
     void dfs(int node, vector<vector<int>>& adj, ll& cnt, vector<int>& vis){
        vis[node] = 1;
        cnt++;
        for(auto& i: adj[node]){
            if(vis[i]==0) dfs(i,adj,cnt,vis);   
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        ll ans = ((ll)n*(n-1))/2;
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ll cnt = 0;
                dfs(i,adj,cnt,vis);
                ans -= (cnt*(cnt-1))/2;
            }
        }
        return ans;
        
    }
};