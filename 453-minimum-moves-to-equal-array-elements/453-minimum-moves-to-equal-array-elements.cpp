//The appraoch goes like: rather than incrementing n-1 elements, simply make all elements equal to minimum element (choose the highest element and decrease it by 1 in one move.)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int min = *min_element(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            ans+= nums[i]-min;
        }
        return ans;
    }
};