class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>v(5,1);
        
        for(int i=0;i<n;i++)
        {
            int sum = std::accumulate(v.begin(), v.end(), 0);
            vector<int>temp(v);
            int back=0;
            for(int i=0;i<5;i++)
            {
                v[i]= sum-back;
                back+=temp[i];
                
            }
            // for(auto x:v)cout<<x<<" ";
            // cout<<endl;
        }
        
        return v[0];
    }
};