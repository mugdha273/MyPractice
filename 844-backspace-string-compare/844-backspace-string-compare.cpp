class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n= s.length();
        int m = t.length();
        
        string a="";
        string b="";
        
        int k=0;
        
        while(n--)
        {
            if(s[n]=='#')k++;
            
            
            if(k==0)
            {
                a+=s[n];
            }
            
            if(k>0 && s[n]!='#')
            {
                k--;
            }
            
        }
        k=0;
        
        while(m--)
        {
            if(t[m]=='#')k++;
            
            
            if(k==0)
            {
                b+=t[m];
            }
            
            if(k>0 && t[m]!='#')
            {
                k--;
            }
            
        }
        
        // cout<<a<<endl;
        // cout<<b<<"\n";
        
        return a==b;
    }
};