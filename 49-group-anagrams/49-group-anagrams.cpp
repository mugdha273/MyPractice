class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        
        for(auto x:strs){

            string temp=x;

            sort(x.begin(),x.end());

            mp[x].push_back(temp);


        }
    
        for(auto x:mp){

            vector<string>temp=x.second;

            ans.push_back(temp);
        }
        return ans;
        
    }
};