class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.size()!=g.size()) return false;
        int n= s.size();
        if(s==g) return true;
        
        for(int i=1; i<n; i++)
        {
            string a= s.substr(0,i+1);
            string b= s.substr(i+1, s.size()-a.size());
            cout<<a<<" "<<b<<" ";
            b+=a;
            cout<<b<<endl;
            if(b==g) return true;
        }
        
        return false;
    }
};