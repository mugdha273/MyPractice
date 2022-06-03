class Solution {
public:
    vector<int>right(vector<int>& arr, int n)
    {
        vector<int>right(n);
         stack<int> st;
         for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        return right;
    }
    
    vector<int>left(vector<int>& arr, int n)
    {
         vector<int>left(n);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        return left;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>r = right(arr,arr.size());
        vector<int>l= left(arr,arr.size());
        int sum=0;
        int mod = pow(10,9)+7;

        for(int i=0; i<arr.size();i++)
        {
            long long prod = (l[i]*r[i])%mod;
            prod = (prod*arr[i])%mod;
            sum = (sum + prod)%mod;
        }
        return sum%mod;
    }
};