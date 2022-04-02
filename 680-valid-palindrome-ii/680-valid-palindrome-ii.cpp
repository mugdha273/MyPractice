class Solution {
public:
    bool validPalindrome(string s) {
        
        int i  = 0;
        int j = s.size()-1;
        int count1=0;
        
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else if(s[i]!=s[j])
            {
                    i++;
                    count1++;   
            }
        }
        
        i  = 0;
        j = s.size()-1;
        int count2 = 0;
        
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else if(s[i]!=s[j])
            {
                    j--;
                    count2++;   
            }
        }
        
        if(count1<=1 || count2<=1) return true;
        
        return false;
        
    }
};