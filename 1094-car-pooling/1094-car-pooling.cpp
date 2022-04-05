class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int far=0;
        
        for(int i=0; i<trips.size(); i++)
        {
            far = max(far, trips[i][2]);
        }
         cout<<far<<endl; 
        bool ans=0;
        
        vector<int>vec(far +1, 0);
        
        for(int i=0; i<trips.size(); i++)
        {
            for(int j= trips[i][1]; j< trips[i][2]; j++)
            {
                vec[j] += trips[i][0];
                if(vec[j]> capacity) ans=1;
            }
            // cout<<endl;
        } 
        
        // for(auto x: vec)
        // {
        //     cout<<x<<" ";
        // } 
        // cout<<endl;
        
        if(ans==1) return false;
        
        return true;
    }
};