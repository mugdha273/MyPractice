class Solution {
public:
    
    //[1,1,-1, -1, -1]
        
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&col)
    {
        if(col[node] == -1) col[node] = 1; 
        for(auto child: graph[node])
        {
            if(col[child] ==-1)
            {
                col[child] = 1- col[node];
                if(!dfs(child, graph, col)) return false;
            }
            
            else if(col[child] ==col[node]) return false;
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size(); //4
        vector<int>col(V+1, -1); // [-1, -,1, -1, -1, -1]
        
        for(int i=0; i<V; i++)
        {
            if(col[i] == -1)
            {
                if(!dfs(i, graph, col)) return false;
            }
            
            
        }
        
        // i=0 dfs(0, graph, col) //[1,-1,-1, -1, -1]
        
        // i=0 dfs(1, graph, col) 
        
        return true;
    }
};