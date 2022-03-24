class Solution {
public:
    int minimumDeletions(vector<int>& v) {
        
       int j = std::max_element(v.begin(),v.end()) - v.begin();
       int i = std::min_element(v.begin(),v.end()) - v.begin();
        
       int n = v.size();
        
       if (i>j)
       {
           int temp=j;
           j=i;
           i=temp;
       }
        
        return min(j+1, min(n-i, i+1+n-j));
        
    }
};