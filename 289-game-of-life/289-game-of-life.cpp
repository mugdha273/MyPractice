class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int one = 0, z = 0;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1) one++;
                else if(i-1>=0 && j-1>=0) z++;
                if(i-1>=0 && board[i-1][j]==1)one++;
                else if(i-1>=0)z++;
                if(i-1>=0 && j+1<m && board[i-1][j+1]==1)one++;
                else if(i-1>=0 && j+1<m) z++;
                if(j+1<m && board[i][j+1]==1)one++;
                else if(j+1<m)z++;
                if(j+1<m && i+1<n && board[i+1][j+1]==1)one++;
                else if(j+1<m && i+1<n) z++;
                if(i+1<n && board[i+1][j]==1)one++;
                else if(i+1<n) z++;
                if(i+1<n && j-1>=0 && board[i+1][j-1]==1)one++;
                else if(i+1<n && j-1>=0) z++;
                if(j-1>=0 && board[i][j-1]==1)one++;
                else if(j-1>=0) z++;
                if(board[i][j]==1){
                    if(one==2 || one==3)ans[i].push_back(1);
                    else ans[i].push_back(0);
                }
                else{
                    if(one==3) ans[i].push_back(1);
                    else ans[i].push_back(0);
                }
            }
        }
        board = ans;
        
    }
};