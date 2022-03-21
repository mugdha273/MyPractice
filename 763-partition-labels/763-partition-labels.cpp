class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch] = i;
        }

        vector<int> ans;
        int a = -1;
        int b = 0;
        
        for(int i = 0; i < s.size(); i++){
            b = max(b, mp[s[i]]);
            if(b == i){

                ans.push_back(b - a);
                a = b;
            }
        }
        return ans;
        
    }
};