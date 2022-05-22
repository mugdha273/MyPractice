class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n= nums2.size();
        stack<int>st;
        vector<int>ans;
        unordered_map<int, int> umap;
        
        for(int i=n-1; i>=0; i--)
        {
            
            if(st.size()==0)
            {
                 umap[nums2[i]] = -1;
            }
            else if(st.size()>0 && st.top()>nums2[i])
            {
                 umap[nums2[i]] = st.top();
            }
            else if (st.size()>0 && st.top()<= nums2[i] )
            {
                while(st.size()>0 && st.top()<=nums2[i])
                {
                    st.pop();
                }
                
                if(st.size()==0)
                {
                    umap[nums2[i]] = -1;
                }
                else
                {
                    umap[nums2[i]] = st.top();
                }
            }
            st.push(nums2[i]);
        }
        
         for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(umap[nums1[i]]);
        }
        
        
        return ans;
    }
};