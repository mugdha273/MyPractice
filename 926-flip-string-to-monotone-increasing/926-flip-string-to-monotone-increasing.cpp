class Solution {
public:
    //ek baar 1 aana start ho jae so getting 0 is like meeting satan! (〃￣︶￣)人(￣︶￣〃)
    
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int ans=0,ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(ones!=0){
                    ones--;
                    ans++;
                }
            }
            else{               
                ones++;
            }
        }
        return ans;
    }
};