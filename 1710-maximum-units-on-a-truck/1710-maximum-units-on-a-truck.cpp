class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxtypes, int truckSize) {
        int ans = 0;
        sort(boxtypes.begin(), boxtypes.end(), cmp);
        
        // for(int j=0; j<boxtypes.size(); j++)
        // {
        //     cout<<boxtypes[j][0]<<" "<<boxtypes[j][1]<<endl;
        // }
        
        int i=0;
        
        while(truckSize>0 && i<boxtypes.size()){

            if(truckSize-boxtypes[i][0]>0){
                truckSize-=boxtypes[i][0];
                ans += (boxtypes[i][0]*boxtypes[i][1]);
            }

            else{
                ans += (truckSize*boxtypes[i][1]);
                truckSize = 0;
            }
            i++;
        }
        return ans;
    }
};