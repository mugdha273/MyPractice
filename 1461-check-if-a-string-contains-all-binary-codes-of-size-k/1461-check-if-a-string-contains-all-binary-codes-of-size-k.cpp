class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>t;
        
        if (k > s.size()) return false;
        
        for(int i=0; i<s.length()-k+1;i++)
        {
            string p= s.substr(i,k);
            // cout<<p<<endl;
            t.insert(p);
        }
        if(t.size()==pow(2,k))
        return true;
        else return false;
    }
};