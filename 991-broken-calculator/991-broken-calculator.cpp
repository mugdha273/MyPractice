class Solution {
public:
    int brokenCalc(int s, int t) {
        
        int count=0;
        
        while(t>s)
        {
          if (t%2==0)t = t/2;
            
          else t++;
            
            ++count;
        }
        
        
        return count + s-t;
    }
};