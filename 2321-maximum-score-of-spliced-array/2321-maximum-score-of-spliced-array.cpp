class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int currSum=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            sum = max(currSum,sum);
            if(currSum<0)
            {
                currSum=0;
            }
            currSum+= nums[i];
        }
        
        return max(currSum,sum);
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int sum1= 0,sum2=0;
        int n= nums1.size();
        
        vector<int>vec1(n);
        vector<int>vec2(n);
        
        for(int i=0; i<n; i++)
        {
            sum1+=nums1[i];
            sum2+=nums2[i];
            vec1[i]= nums1[i]-nums2[i];
            vec2[i]= nums2[i]-nums1[i];
        }
        
        int ans1=maxSubArray(vec1);
        int ans2=maxSubArray(vec2);
        
        return max(ans1+sum2, ans2+sum1);
    }
};