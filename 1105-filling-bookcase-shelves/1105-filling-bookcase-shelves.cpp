
class Solution {
public:
    int maxW;
    int dp[1002][1002];
    int minHeightShelves(vector<vector<int> >& books, int shelfWidth) {
        maxW= shelfWidth;
        memset(dp,-1,sizeof(dp));
        return memo(0,0,0,true,books);
}

int memo(int i,int currentW,int height,bool first,vector<vector<int> >& books)
{

        if(i==books.size())
                return height;

        if(dp[i][currentW]!=-1)
                return dp[i][currentW];


        if(first==true)
        {
                height=books[i][1];
                dp[i][currentW]=memo(i+1,currentW+books[i][0],height,false,books);
                return dp[i][currentW];
        }

        else if(currentW+books[i][0]<=maxW)
        {
                dp[i][currentW]=min(memo(i+1,currentW+books[i][0],max(height,books[i][1]),false,books),
                                  memo(i,0,0,true,books)+height);
                return dp[i][currentW];
        }


        else
        {
                dp[i][currentW]=memo(i,0,0,true,books)+height;
                return dp[i][currentW];
        }
}
};