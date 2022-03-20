class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size(), ans = INT_MAX;
    int a = tops[0], b = bottoms[0], tmp = 0;
    bool f = true;
    for(int i = 0; i < n && f; i++)
        if(a != tops[i]) 
        {
            if(a != bottoms[i])
                f = false;
            else
                tmp++;
        }
    
    if(f)
        ans = min(ans, tmp);
    
    tmp = 0, f = true;
    for(int i = 0; i < n && f; i++)
        if(a != bottoms[i]) 
        {
            if(a != tops[i])
                f = false;
            else
                tmp++;
        }
    
    if(f)
        ans = min(ans, tmp);
    
    tmp = 0, f = true;
    for(int i = 0; i < n && f; i++)
        if(b != bottoms[i]) 
        {
            if(b != tops[i])
                f = false;
            else
                tmp++;
        }
    
    if(f)
        ans = min(ans, tmp);
    
    tmp = 0, f = true;
    for(int i = 0; i < n && f; i++)
        if(b != tops[i]) 
        {
            if(b != bottoms[i])
                f = false;
            else
                tmp++;
        }
    
    if(f)
        ans = min(ans, tmp);
    
    return ans == INT_MAX ? -1 : ans;
    }
};