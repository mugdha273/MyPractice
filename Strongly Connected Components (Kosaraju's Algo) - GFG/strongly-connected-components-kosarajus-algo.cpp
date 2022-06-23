// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	vector<int> rev[100005];
    int vis[100005];
    stack<int> st;
    
    void dfs(int node,vector<int> adj[],int x){
    vis[node]=1;
    for(int i:adj[node]){
        if(vis[i]==0){
            dfs(i,adj,x);
        }
    }
    if(x)
       st.push(node);
}
    
    int kosaraju(int V, vector<int> adj[])
   {
       
       for(int i=0;i<V;i++){
           rev[i].clear();
           vis[i]=0;
       }
       
       for(int i=0;i<V;i++){
           for(int j:adj[i]){
               rev[j].push_back(i);
           }
       }
       
       for(int i=0;i<V;i++){
           if(vis[i]==0){
               dfs(i,adj,1);
           }
       }
       
       for(int i=0;i<V+1;i++){
           vis[i]=0;
       }
       int cnt=0;
       while(!st.empty()){
           int cur=st.top();
           st.pop();
           if(vis[cur]==0){
                cnt++;dfs(cur,rev,0);
           }
       }
       return cnt;
       //code here
   }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends