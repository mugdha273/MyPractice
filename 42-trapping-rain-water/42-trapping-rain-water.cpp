class Solution {
public:
    int trap(vector<int>& v) {
        
        int max2=INT_MIN, max1= INT_MIN;
        int ans=0;
        vector<int>vec;
        vector<int>vec1;
        
        for(int i= v.size()-1; i>=0; i--)
        {
            max1= max(max1,v[i]);
            vec.push_back(max1);
        }
        reverse(vec.begin(),vec.end());
        
        for(int i=0; i<v.size();i++)
        {
            max2= max(max2,v[i]);
            vec1.push_back(max2);
        }
        
        // for(auto x:vec1) cout<<x<<" ";
        // cout<<endl;
        
        for(int i=0; i<v.size();i++)
        {

            if(min(vec[i],vec1[i])-v[i]>0) ans+=min(vec[i],vec1[i])-v[i];
        }
        
        return ans;
    }
};