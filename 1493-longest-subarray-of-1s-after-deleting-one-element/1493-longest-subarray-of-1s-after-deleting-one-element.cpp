class Solution {
public:
    
//     pair<int,int> countOne(vector<int>& nums, int idx)
//     {
//         int a=0;
//         int b=0;
        
//         for(int i=idx+1; i<nums.size(); i++)
//         {
//             if(nums[i]==0) break;
//             a++;
//         }
//         for(int i=idx-1; i>=0; i--)
//         {
//             if(nums[i]==0) break;
//             b++;
//         }
//         return {a,b};
//     }
    
//     int longestSubarray(vector<int>& nums) {
//         int ans=0;
//         int n= nums.size();
//         for(int i=0; i<n; i++)
//         {
//             if(nums[i]==1) continue;
//             pair<int,int>p= countOne(nums,i);
//             ans= max(ans,p.first+p.second);
//         }
//         return ans;
//     }
    int longestSubarray(vector<int>& nums) {
   int cnt1=0,cnt2=0,i=0,j=0,ans=0;
        while (j<nums.size()) {
            if (nums[j]==1) cnt1++;
            if (nums[j]==0) cnt2++;
            while (cnt2>1) {
                if (nums[i]==1) cnt1--;
                if (nums[i]==0) cnt2--;
                i++;
            }
            if (cnt2) ans=max(ans,cnt1);
            else ans=max(ans,cnt1-1);
            j++;
        }
        return ans;
    }
};