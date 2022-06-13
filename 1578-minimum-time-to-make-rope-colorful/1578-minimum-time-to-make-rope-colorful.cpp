class Solution {
public:
    int minCost(string col, vector<int>& time) {
        int n= col.size();
        int sum=0;
        int i=0;
        
        while(i<n)
        {
            
            if(col[i]==col[i+1])
            {
                int j=time[i];
                while(col[i]==col[i+1] && i<n) 
                {
                    j=max(j,time[i+1]);
                    sum+=time[i];
                    i++;
                }
                sum+=time[i];
                sum-=j;
            }
            else
            {
                i++;
            }
            
        }
        
        return sum;
    }
};