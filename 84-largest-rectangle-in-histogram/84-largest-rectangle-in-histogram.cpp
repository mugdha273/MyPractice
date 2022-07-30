class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr,nsl;
        stack<pair<int, int>> l,r;
        
        for(int i=0;i<heights.size();i++)  
        {
            if(l.size()==0)
                nsl.push_back(-1);
            else if(l.size()>0 && l.top().first<heights[i])
                nsl.push_back(l.top().second);
            else if(l.size()>0 && l.top().first>=heights[i])
            {
                while(l.size()>0 && l.top().first>=heights[i])
                    l.pop();
                if(l.size()==0)
                    nsl.push_back(-1);
                else
                    nsl.push_back(l.top().second);
            }
            l.push({heights[i], i});
        }
        
        for(int i=heights.size()-1;i>=0;i--)  
        {
            if(r.size()==0)
                nsr.push_back(heights.size());
            else if(r.size()>0 && r.top().first<heights[i])
                nsr.push_back(r.top().second);
            else if(r.size()>0 && r.top().first>=heights[i])
            {
                while(r.size()>0 && r.top().first>=heights[i])
                    r.pop();
                if(r.size()==0)
                    nsr.push_back(heights.size());
                else
                    nsr.push_back(r.top().second);
            }
            r.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());
        
        int mx=0;
        for(int i=0;i<heights.size();i++)
        {
            int p= nsr[i]-nsl[i]-1;
           p*=heights[i];
            mx= max(mx, p); 
        }
        
        return mx;
        
        
    }
};