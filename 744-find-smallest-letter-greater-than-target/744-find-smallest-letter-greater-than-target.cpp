class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n= letters.size();
        for(int i=0; i<n; i++)
        {
            letters[i] = letters[i]-'a';
        }
        
        int t= target-'a';
        
        int low=0, high = n-1, res=0;
        
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            // if(letters[mid]==t) low = mid+1;
            if(letters[mid]<= t) low = mid+1;
            else
            {
                res= mid;
                high= mid-1;
            }
            
        }
        
        return letters[res]+'a';
    }
};