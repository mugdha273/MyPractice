class Solution {
public:
    vector<int> nsl(vector<int>&a)
{
    int n=a.size();
    vector<int>left;
    stack<pair<int,int>>st;

    for(int i=0;i<n;i++)
    {
        if(st.size()==0)
        {
            left.push_back(-1);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first<a[i])
        {
            left.push_back(st.top().second);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first>=a[i])
        {
            while(st.size()>0 && st.top().first>=a[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                left.push_back(-1);
                st.push({a[i],i});
            }
            else
            {
                 left.push_back(st.top().second);
                 st.push({a[i],i});
            }
        }
    }
    return left;
    
}
vector<int> nsr(vector<int>&a)
{
    int n=a.size();
    vector<int>right;
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--)
    {
        if(st.size()==0)
        {
            right.push_back(n);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first<a[i])
        {
            right.push_back(st.top().second);
            st.push({a[i],i});
        }
        else if(st.size()>0 && st.top().first>=a[i])
        {
            while(st.size()>0 && st.top().first>=a[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                right.push_back(n);
                st.push({a[i],i});
            }
            else
            {
                 right.push_back(st.top().second);
                 st.push({a[i],i});
            }
        }
    }
    reverse(right.begin(),right.end());
    return right;
    
}
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
         vector<int>left=nsl(a);
    vector<int>right=nsr(a);

    int ans=0;
    for(int i=0;i<n;i++)
    {
        
        ans=max(ans,a[i]*(right[i]-left[i]-1));
    }
        
    return ans;
        
    }
};