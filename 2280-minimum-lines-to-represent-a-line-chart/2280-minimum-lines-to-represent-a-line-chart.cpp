class Solution {
public:
    
    int minimumLines(vector<vector<int>>& s) {
        sort(s.begin(),s.end());
         if(s.size()<=1)return 0;
        int n= s.size();
        
        int lines=1;
        
        for(int i=1; i<n-1; i++)
        {
            long double a = s[i-1][0];
            long double b = s[i-1][1];
            
            long double x = s[i][0]; long double y= s[i][1];
            
            long double p = s[i+1][0]; long double q = s[i+1][1];
            
            long double s1 = (long double)(b-y)/(a-x);
            long double s2 = (long double)(q-y)/(p-x);
            
            if(s1!=s2) lines++;
        }
        
        return lines;
    }
};