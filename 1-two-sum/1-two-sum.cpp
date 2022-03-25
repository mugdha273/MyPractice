class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<pair<int,int>>arr;
        for(int i=0; i<n;i++) arr.push_back(make_pair(nums[i],i)); 
        
        sort(arr.begin(), arr.end()); 
        int l = 0, r = n- 1;
        
        while(l<r)
        {
            int sum = arr[l].first + arr[r].first;
            cout<<l<<" "<<r<<" "<<sum<<endl;
            
            if (sum==target) return { arr[l].second,arr[r].second};
            if(sum>target)
            {
                r=r-1;
            }
            else l=l+1;
            
        }
        return {};
    }
};