class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int n=gas.size();
        for(int i=0; i<n; i++)
        {
            sum+= gas[i]-cost[i];
        }
        
        if(sum>=0)
        {
            int curr=0;int s=0;
            for(int i=0; i<n; i++)
            {
                curr+= gas[i]-cost[i];
                
                if(curr<0)
                {
                    curr=0;
                    s=i+1;
                }
            }
            
            return s;
            
        }
        
        return -1;
    }
};