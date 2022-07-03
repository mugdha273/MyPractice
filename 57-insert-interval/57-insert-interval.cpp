class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>vec;
        
        int n= intervals.size();
        int s = intervals[0][0];
        int e = intervals[0][1];
        
        for(int i=1; i<n ;i++)
        {
            if(e<intervals[i][0])
            {
                vec.push_back({s,e});
                s= intervals[i][0];
                e= intervals[i][1];
            }
            else if (e>=intervals[i][0]) {
                e = max(e,intervals[i][1]);
            }
        }
        vec.push_back({s,e});
        return vec;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};