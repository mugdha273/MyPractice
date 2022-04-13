class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a = 0, b = n-1;
        int x = 0, y = n-1;
        int z = 0;

        vector<vector<int>> v(n, vector<int> (n));
        while(a <= b && x <= y)
        {
            for(int i = x; i <= y; ++i)
                v[a][i] = ++z;
				
            for(int i = a+1; i <= b; ++i)
                v[i][y] = ++z;
				
            if(a < b && x < y)
            {

                for(int i = y-1; i>x; --i)
                    v[b][i] = ++z;
					
					for(int i = b; i>a; --i) 
                    v[i][x] = ++z;
            }
            ++a;
            --b;
            ++x;
            --y;
        }
        return v;
        
    }
};