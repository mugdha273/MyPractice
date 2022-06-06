class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(int idx, vector<int>& c, int target, vector<int>&sub)
    {
        if(target==0){
            ans.push_back(sub);
            return;
        }

        
        for(int i=idx; i<c.size();i++)
        {
            if(i>idx && c[i]==c[i-1])continue;
            if(c[i]>target) break;
            
            sub.push_back(c[i]);
            helper(i+1, c, target-c[i],sub);
            sub.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>sub;
        helper(0,candidates,target,sub);
        
        return ans;
    }
};