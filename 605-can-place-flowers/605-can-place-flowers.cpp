class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans=0;
        if(flowerbed.size()==1)
        {
            if(flowerbed[0]==0 && n==1)return true;
            if(n==0)return true;
            else return false;
        }
        for(int i=0; i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0 && i>1 && i<flowerbed.size()-2)
            {
                if(flowerbed[i+1]!=1&& flowerbed[i-1]!=1)
                {
                    ans++;
                    flowerbed[i]=1;
                }
            }
            else if (flowerbed[i]==0 && i==flowerbed.size()-1)
            {
                if(flowerbed[i-1]!=1)
                {
                    ans++;
                    flowerbed[i]=1;
                }
            }
            else if((flowerbed[i]==0 && i==0))
            {
               if(flowerbed[i+1]!=1)
                {
                    ans++;
                    flowerbed[i]=1;
                }         
            }
        }

        if(ans>=n)return true;
        
        return false;
        
    }
};