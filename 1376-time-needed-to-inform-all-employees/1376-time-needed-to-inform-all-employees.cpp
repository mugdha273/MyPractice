class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>adj(n);
        int ans=0;
        
        for(int i=0; i<manager.size();i++)
        {
            if(i!=headID) adj[manager[i]].push_back(i);
        }
        
        vector<int>vis(n+1,0);
        
         queue<pair<int,int>>q;
         q.push({headID,0});

        vis[headID]=1;
        
        while(!q.empty())
        {
            pair<int,int> node= q.front();
            q.pop();
            ans= max(informTime[node.first]+ node.second, ans);
            
            for(auto x: adj[node.first])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push({x, informTime[node.first]+ node.second});
                }
            }
        }
        
        return ans;
    }
};