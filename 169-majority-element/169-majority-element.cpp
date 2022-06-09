//Moore's Voting Algorithm 
//no fun in space n, give it in 1!

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ansIdx=0;
        int count=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            
            if(nums[ansIdx]== nums[i]) count++;
            else count--;
            
            if(count==0)
            {
                ansIdx=i;
                count=1;
            }
        }
        
        return nums[ansIdx];
    }
};