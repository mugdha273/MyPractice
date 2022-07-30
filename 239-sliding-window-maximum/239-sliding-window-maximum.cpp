class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        map<int, int, greater<>> mp;
        
        int i = 0, j = 0;
        
        while(j < nums.size())
        {
            mp[nums[j]]++;
            
			if(j-i+1 < k) j++;
						
            else if(j-i+1 == k)
            {
                vec.push_back(mp.begin()->first);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++; j++;
            }
        }
        
        return vec;
    }
};