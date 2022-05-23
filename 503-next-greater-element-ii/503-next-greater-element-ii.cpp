class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int>st;
        vector<int>ans,r;
        int n= nums.size();
        
        for(auto x:nums)
            r.push_back(x);
        
        for(auto x:nums)
            r.push_back(x);
        
        for(int i=r.size()-1; i>=0; i--)
        {
            
            if(st.size()==0)
            {
                 ans.push_back(-1);
            }
            else if(st.size()>0 && st.top()>r[i])
            {
                 ans.push_back(st.top());
            }
            else if (st.size()>0 && st.top()<= r[i] )
            {
                while(st.size()>0 && st.top()<=r[i])
                {
                    st.pop();
                }
                
                if(st.size()==0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(st.top());
                }
            }
            st.push(r[i]);
        }
        vector<int>final;
        
        for(int i= ans.size()-1; i>=n; i--)
        {
            final.push_back(ans[i]);
        }
        
         return final;
    }
};