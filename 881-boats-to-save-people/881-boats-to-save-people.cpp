class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count=0;        
        int n= people.size();
        
        int i=0, j=n-1;
        
        sort(people.begin(), people.end());
        
        while(i<=j)
        {
            if(people[i]+ people[j]<=limit)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            
            count++;
        }
        
        
        return count;
        
    }
};