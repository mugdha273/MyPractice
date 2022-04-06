class Solution {
public:
    
    static bool Compare_(const pair<int,int> &a ,const  pair<int,int> &b){
        return a.second < b.second;
        
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>s;
        
        for(int i=0; i<nums.size(); i++)
        {
            s.push_back({i, nums[i]});
        }
        
        sort(s.begin(), s.end(), Compare_);
        vector<int>vec;
        int i=0;
        int j = s.size()-1;
        
        while(i<j)
        {
            if( s[i].second + s[j].second == target ) 
            { 
                vec.push_back(s[i].first);
                vec.push_back(s[j].first);
                return vec;
            }
            if(s[i].second + s[j].second > target)
            {
                j--;
            } 
            else
            {
                i++;
            }
        }
        
        return vec;
    }
};