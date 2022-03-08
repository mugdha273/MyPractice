class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int sum=0;
        
        for(int i=0; i<gas.size(); i++)
        {
            sum+= gas[i]-cost[i];
        }
        
        if(sum>=0)
        {
            int curr = 0;
            int s = 0;

            for(int i =0; i<gas.size(); i++){

                curr = curr + (gas[i] - cost[i]);

                if(curr< 0){
                    curr = 0;
                    s = i +1;
                }
            }

            return s;
        }
        else
        {
            return -1;
        }
    return 0;
    }
};