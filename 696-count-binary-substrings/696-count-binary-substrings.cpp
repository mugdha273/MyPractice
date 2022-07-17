class Solution {
public:
    int countBinarySubstrings(string s) {
         int prev=0, curr=1 , ans=0;
        
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                ans+=min(curr,prev);
                prev=curr;
                curr=1;
            }else{
                curr++;
            }
        }
        
         return ans+min(curr,prev);
    }
};