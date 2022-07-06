class Solution {
public:
    long long int Calculate(vector<int>& nums,int k){
        long long int NumberOfHours=0;
        for(int i=0;i<nums.size();i++){
            NumberOfHours+=(nums[i]%k==0) ? nums[i]/k : (nums[i]/k)+1;
        }
        return NumberOfHours;
    }
    
    
    int minEatingSpeed(vector<int>& nums, int H) {
        int left=1;
        int right=1000000000;
        int ans=0;
        while(left<=right){
           int k=left+(right-left)/2;    
            
           long long int NumberOfHours = Calculate(nums,k);
            
            if(NumberOfHours>H){
                left=k+1;
            }
            else if(NumberOfHours<=H){
                ans=k;
                right=k-1;
            }
        }
        return ans;
        
    }
};