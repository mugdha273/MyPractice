class Solution {
public:

    int dp[101];

    int numDecodings(string &s) {

        memset(dp, -1, sizeof dp);
        int ans = help(s,0);
        return ans;
    }
	
	int help(string&s,int pos){
        if(pos >= s.size())return 1;

        if(dp[pos] != -1) return dp[pos];
        
        if(s[pos] == '0')return dp[pos] = 0;
        
        //decode normally
        int ans = help(s,pos+1);
        
        //10 to 19 case
        if(s[pos] == '1' && pos +1 < s.size())ans += help(s,pos+2);
        
        //20 to 26 case
        else if(s[pos] == '2' && pos +1 < s.size() && s[pos+1] <= '6')ans += help(s,pos+2);
        
        
        return  dp[pos] = ans;
    }
};