//kya tha ye bhaisahab!

class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(int idx, int target, vector<int> &candidates, vector<int>&sub) {
        if(idx==candidates.size())
        {
            if(target==0) ans.push_back(sub);
            
            return;
        }
        //utha le re baba
        
        if(candidates[idx]<=target)
        {
            sub.push_back(candidates[idx]);
            helper(idx, target-candidates[idx],candidates, sub);
            sub.pop_back();
        }
        
        //na mat utha
        helper(idx+1, target, candidates, sub);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>vec;
        
        helper(0, target, candidates,vec);
        return ans;
    }
};