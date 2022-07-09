class Solution {
public:
    
    //O(n^3)
    /*
    int numTeams(vector<int>& arr) {
        int n= arr.size();
        int ans{0};
        
        for(int i=0; i<n; i++)
        {
            for(int k=n-1; k>=0; k--)
            {
                for(int j=i+1; j<k; j++)
                {
                    if(arr[i]<arr[k])
                    {
                        if(arr[j]>arr[i] && arr[j]<arr[k]) ans++;
                    }
                    else if(arr[i]>arr[k])
                    {
                        if(arr[j]<arr[i] && arr[j]>arr[k]) ans++;
                    }
                    else break;
                }
            }
        }
        return ans;
    }
    */
    
    vector<int>helper1(vector<int>& arr)
    {
        vector<int>ans;
        int n= arr.size();
        
        for(int i=0; i<n; i++)
        {
            int cnt=0;
            
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]<arr[j]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
    vector<int>helper2(vector<int>& arr)
    {
        vector<int>ans;
        int n= arr.size();
        
        for(int i=0; i<n; i++)
        {
            int cnt=0;
            
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]>arr[j]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
     int numTeams(vector<int>& arr) {
         vector<int>vec1= helper1(arr);
         vector<int>vec2= helper2(arr);
         int n= arr.size();
         // for(auto x:vec1)cout<<x<<" ";
         // cout<<endl;
         // for(auto x:vec2)cout<<x<<" ";
         // cout<<endl;
         int ans=0;
         
         for(int i=0; i<n; i++)
        { 
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]>arr[j]) ans+=vec2[j];
                if(arr[i]<arr[j]) ans+=vec1[j];
            }
        }
             
         return ans;
     }
    
};