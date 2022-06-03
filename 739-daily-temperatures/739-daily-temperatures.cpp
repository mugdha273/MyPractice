class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr, int n){
        // Your code here
        vector<int>vec;
        stack<pair<int,int>>s;
        
        for(int i= n-1; i>=0; i--)
        {
            if(s.size()==0) vec.push_back(0);
            else if(s.size()>0 && s.top().first>arr[i]) vec.push_back(s.top().second-i);
            else if(s.size()>0 && s.top().first<=arr[i])
            {
                while(s.size()>0 && s.top().first<=arr[i])
                {
                    s.pop();
                }
                
                if(s.size()==0) vec.push_back(0);
                 else{
                   vec.push_back(s.top().second-i);
               }
                
            }
            s.push({arr[i],i});
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return nextLargerElement(temperatures, temperatures.size());
    }
};