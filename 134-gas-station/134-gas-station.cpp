class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int>f;
        
        for(int i=0; i<gas.size(); i++)
        {
            f.push_back(gas[i]-cost[i]);
        }
        
        int sum=0;
        
        for(auto x: f)sum+=x;
        
        
        if(sum>=0)
        {
            int totalcost = 0;
        int currcost = 0;
        int startIndex = 0;
        
        for(int i =0; i<gas.size(); i++){
            
            currcost = currcost + (gas[i] - cost[i]);
            

            if(currcost < 0){
                currcost = 0;
                startIndex = i +1;
            }
        }
        
        return startIndex;
        }
        else
        {
            return -1;
        }
    return 0;
    }
};