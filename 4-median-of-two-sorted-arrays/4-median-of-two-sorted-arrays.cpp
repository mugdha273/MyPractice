class Solution {
public:
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        
        int x= nums1.size()-1, y= nums2.size()-1;
        int i=0,j=0;
        while(i<= x && j<= y)
        {
            if(nums1[i]<nums2[j])
            {
                res.push_back(nums1[i++]);
            }
            else res.push_back(nums2[j++]);
        }
        while(i<=x)res.push_back(nums1[i++]);
        while(j<=y)res.push_back(nums2[j++]);
        
        int s = res.size();
        double ans;
//         for(auto x: res)cout<<x<<" ";
//         cout<<"\n";
        
//         cout<<s<<endl;
        if(s%2 == 0)
        {
            ans = (res[(s/2)-1] + res[s/2])*0.5;
            
            return ans;
            
        }
        else
        {
            ans = res[s/2];
            return ans;
        }
        
    }
};