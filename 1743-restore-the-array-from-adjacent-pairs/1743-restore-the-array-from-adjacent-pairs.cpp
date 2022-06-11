class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        int n = adj.size()+1,head;
        vector<int>vec(n,0);
        unordered_map<int, vector<int>>ps;
        int i=0;
       
        for(auto x:adj)
        {
            ps[x[0]].push_back(x[1]);
            ps[x[1]].push_back(x[0]);
        }
        
        for(auto x:ps)
        {
            if(x.second.size()==1)
            {
                head=x.first;
                vec[0]=head;
                vec[1]= x.second[0];
                break;
            }
        }
        
        
        for(int i=2;i<n;i++)
        {
            vector<int>check= ps[vec[i-1]];
            if(check[0]!=vec[i-2])
            {
                vec[i]=check[0];
            }
            else
            {
                vec[i]=check[1];
            }
        }
        

        
        return vec;
    }
};