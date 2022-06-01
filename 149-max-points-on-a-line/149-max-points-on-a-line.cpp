class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i=0; i<points.size();++i){
            map<long double,int> h;
            int same = 1;
            int temp = 0;
            for(int j=i+1;j<points.size();++j){
                if(points[i][0] == points[j][0] && points[i][1]==points[j][1]){
                    same++;
                }
                else if(points[i][0]==points[j][0]){
                    h[INT_MAX]++;
                }
                else{
                    long double slope = (long double)(points[i][1] - points[j][1])/(long double)(points[i][0] - points[j][0]);
                    h[slope]++;
                }
            }
            for(auto i : h){
                temp = max(temp,i.second);
            }
            temp +=same;
            result = max(result,temp);
        }
        return result;
    }
};