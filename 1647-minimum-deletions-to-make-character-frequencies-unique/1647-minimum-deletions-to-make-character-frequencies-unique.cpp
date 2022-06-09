class Solution {
public:
    
    int minDeletions(string s) {
        map<char,int>mp;
        int ans=0;
        for(auto x:s) mp[x]++;
        
        map<int,char>m;
        
        for(auto x:mp)
        {
            // cout<<x.first<<" "<<x.second<<" ";
            if(m.count(mp[x.first])>0)
            {
                // cout<<"hi"<<endl;
                int r=mp[x.first];
                // cout<<r<<endl;
                while(m.count(r)>0 && r>0)
                {
                    // cout<<"hello"<<endl;
                    r--;
                    ans++;
                }
                if(r>0)
                {
                    m[r]= x.first;
                }
                
            }
            else
            {
                m[x.second]=x.first;
            }
            cout<<endl;
            // cout<<"***"<<m[x.second]<<endl;
        }
        
        for(auto x:m) cout<<x.first<<" "<<x.second<<endl;
        
        return ans;
    }
};