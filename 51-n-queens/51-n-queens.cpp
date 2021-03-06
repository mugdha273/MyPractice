class Solution {
public:
    vector <vector<string>>ans;
    bool isSafe(int row, int col, vector<string>board, int n)
    {
        int a= row;
        int b= col;
        
        while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }
      
      col = b;
      row = a;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = a;
      col = b;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
        
    }
    
    void solve(int col, vector < string > & board, int n){
        if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, n);
          board[row][col] = '.';
        }
      }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector < string > board(n,s);
      
      solve(0, board, n);
      return ans;
        
    }
};