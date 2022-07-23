class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int,int>mp;
        int x=0;
        for(int i=0; i<rolls.size(); i++)
        {
            mp[rolls[i]]++;
            if(mp.size()==k)
            {
                x++;
                mp.clear();
            }
        }
        return x+1;
    }
};