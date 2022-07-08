class Solution {
public:
    
    bool isValid(string s, string p)
    {
        int m= s.size();
        int diff=0;
        
        for(int i=0; i<m; i++)
            if(s[i]!=p[i]) diff++;
        
        return diff==1?true:false;
    }
    
    int countSubstrings(string s, string t) {
        
        if(s.size()>t.size()) return countSubstrings(t,s);
        
        map<int,vector<string>>mp1;
        map<int,vector<string>>mp2;
        
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                string r =s.substr(i,j-i+1);
                mp1[r.size()].push_back(r);
            }
        }
        
        for(int i=0;i<t.length();i++)
        {
            for(int j=i;j<t.length();j++)
            {
                string r =t.substr(i,j-i+1);
                mp2[r.size()].push_back(r);
            }
        }
        int ans=0;
        
        for(int i=1; i<=mp1.size();i++)
        {
            for(int j=0; j<mp1[i].size();j++)
            {
                for(int k=0; k<mp2[i].size();k++)
                {
                    if(isValid(mp1[i][j],mp2[i][k])) ans++;
                }
            }
        }
        
//         for(auto x:mp1){
//             cout<<x.first<<" ";
//             for(auto y:x.second)
//                 cout<<y<<" ";
//             cout<<endl;
//         }
        
//         cout<<"***"<<endl;
        
//         for(auto x:mp2){
//             cout<<x.first<<" ";
//             for(auto y:x.second)
//                 cout<<y<<" ";
//             cout<<endl;
//         }
        
        return ans;
    }
};