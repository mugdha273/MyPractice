// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> res;
       stack<pair<int, int>> st;
       for (int i=0; i<n; i++) {
           pair<int, int> p = {price[i], 1};
           
           if (st.empty()) st.push(p);
           else {
               if (p.first < st.top().first) {
                   st.push(p);
               }
               else {
                   while (!st.empty() && p.first >= st.top().first) {
                       p.second += st.top().second;
                       st.pop();
                   }
                   st.push(p);
               }
           }
           
           res.push_back(p.second);    
       }
       
       return res;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends