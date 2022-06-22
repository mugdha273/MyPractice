class Solution {
public:
    bool cycle(int node, vector<int>&vis, vector<int>&dfsvis, vector<vector<int>>&graph){
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(int x: graph[node]){
            if(!vis[x]){
                if(cycle(x, vis, dfsvis,graph)){
                    return true;
                }
            }
            
            else{
                if(dfsvis[x]){
                    return true;
                }
            }
        }

        dfsvis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>dfsvis(n, 0);
        
        for(int i = 0; i<n; i++){
            if(vis[i]==0){
                cycle(i,vis, dfsvis, graph);
            }
        }
        
        for(int i = 0;i<n; i++){
            if(dfsvis[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};