class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s1.length();
        int m= s2.length();
        
        if(n==0) return true;
        if(m==0) return false;

        if(n>m) return false;
        
        vector<int> dict(26,0),a(26,0); 
        
        for(char c: s1) a[c-'a']++;
        
        for(int i=0; i<n; i++)
            dict[s2[i]-'a']++;
        
        int i = 0; 
        for(int j=n; j<m; j++){
            if(dict==a) return true;
            
            dict[s2[i++]-'a']--;    
            dict[s2[j]-'a']++;     
        }
        
        if(dict==a) return true; 
        return false;
        
    }
};