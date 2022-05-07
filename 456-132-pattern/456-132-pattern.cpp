class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int r = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; -- i) {
            if (nums[i] < r) return true;
            while (!st.empty() && nums[i] > st.top()) {
                r = st.top(); 
                st.pop();
                
            }
            st.push(nums[i]);
        }
        return false;
    }
};