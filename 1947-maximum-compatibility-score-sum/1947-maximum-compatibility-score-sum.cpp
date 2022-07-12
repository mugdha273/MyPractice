class Solution {
public:
    int ans=0;
    int used[9] = {};
    int calcCompatibility(vector<int>& a1,vector<int>& a2){
        int i=0;
        int matchedAnswers = 0;
        while(i<a1.size()){
            if(a1[i] == a2[i]) matchedAnswers++;
            i++;
        }
        return matchedAnswers;
    }
    
    void helper(int i, int sum, vector<vector<int>>&mat)
    {
        if(i>=mat.size())
        {
            ans= max(ans, sum);
            return;
        }
        
        for(int j=0; j<mat[0].size(); j++)
        {
            if(used[j]) continue;
            used[j]=1;
            helper(i+1, sum+ mat[i][j], mat);
            used[j]=0;
        }
        
    }
    int maxCompatibilitySum(vector<vector<int>>& S, vector<vector<int>>& M) {
        
        int m = S.size(), n = S[0].size();
        // cout<<m<<" "<<n<<"***"<<endl;
        vector<vector<int>>mat(m, vector<int>(m));
        int i=0; 
        for(auto x: S)
        {
            int j=0;
            for(auto y: M)
            {
                mat[i][j]= calcCompatibility(x,y);
                
                // cout<<calcCompatibility(x,y)<<" ";
                // cout<<i<<" "<<j<<"\n";
                j++;
                // if(j==n) j=0;
            }
            cout<<endl;
            i++;
        }
        
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        helper(0,0,mat);
        
        return ans;
    }
};