class Solution {
public:
    string reorganizeString(string st) {
        map<char,int>mp;
        for(auto x:st) mp[x]++;
        
        priority_queue<pair<int, char>> pq;
        
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        string ans="";
        while(pq.size()>1)
        {
            auto [a,b]=pq.top();
            pq.pop();
            auto [c,d]=pq.top();
            pq.pop();
            ans.push_back(b);
            ans.push_back(d);
            a--;
            c--;
            if(a>0){
                pq.push({a,b});
            }
            if(c>0){
                pq.push({c,d});
            }
            
        }
        if(pq.size()==1)
        {
            auto [a,b]=pq.top();
            pq.pop();
            if(a>1) return "";
            ans.push_back(b);
        }
        return ans;
    }
};