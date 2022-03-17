// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        map<int, int>mp;
        int max_freq=0;
        char ans;
        
        sort(str.begin(), str.end());
        
        for(int i=0; i<str.size(); i++)
        {
            mp[str[i]]++;
            
            if(max_freq < mp[str[i]])
            {
                max_freq = mp[str[i]];
                ans = str[i];
            }
            
        }
        
        return ans;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends