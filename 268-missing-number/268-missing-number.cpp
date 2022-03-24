class Solution {
public:
    int missingNumber(vector<int>& a) {
        // int max = *max_element(a.begin(), a.end()); 
        
        // cout<<max<<endl;
        
        vector<int>vec;
        
        for(int i=0; i<=a.size(); i++)
        {
            vec.push_back(i);
        }
        
        sort(a.begin(), a.end());
        
//         for(auto x:a)
//         {
//             cout<<x<<" ";
//         }
//         
        
        for(auto x:vec)
        {
            cout<<x<<" ";
        }
        
        cout<<endl;
        
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]!=vec[i])
            {
                return vec[i];
            }
        }
        
        return vec[vec.size()-1];
    }
};