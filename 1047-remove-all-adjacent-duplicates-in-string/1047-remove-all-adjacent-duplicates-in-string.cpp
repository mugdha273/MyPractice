class Solution {
public:
    string removeDuplicates(string s) {
        string b;
        
        for(auto x:s)
        {
            if(b.size()==0) b.push_back(x);
            else if(x== b.back()) b.pop_back();
            else b.push_back(x);
        }
        
        return b;
    }
};