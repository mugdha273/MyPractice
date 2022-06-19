class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        int n= s.size();
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='0')cnt++;
            else{
                if(k>=pow(2,i)){
                    k-=pow(2,i);
                    cnt++;
                }
            }
            
        }
        return cnt;
        
    
        
    }
};