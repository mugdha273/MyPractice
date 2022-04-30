class Solution {
public:
    
    double dfs(string start, string end, unordered_set<string> &vis, unordered_map<string, vector < pair<string, double>> > mp ){
        if((mp.find(start) == mp.end()) or (mp.find(end) == mp.end())) return -1.0;
        
        if(start == end) return 1.0;
        
        vis.insert(start);
        
        for(auto x : mp[start]){
            if(vis.find(x.first) == vis.end() ){
                auto res = dfs(x.first, end, vis, mp);
                if(res != -1.0){
                    return x.second *res;
                }
            }
        }
        
        return -1.0;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector < pair<string, double>> > mp;
        
        for(int i = 0; i < equations.size(); i++){
            auto eq = equations[i];
            mp[eq[0]].push_back({eq[1], values[i] });
            mp[eq[1]].push_back({eq[0], 1/values[i]});
        }
        
        vector <double> ans;
        
        for(int i = 0; i < queries.size(); i++){
            auto q = queries[i];
            unordered_set<string> vis;
            auto res = dfs(q[0], q[1], vis, mp );
            ans.push_back(res);
        }
        
        return ans;
        
    }
};