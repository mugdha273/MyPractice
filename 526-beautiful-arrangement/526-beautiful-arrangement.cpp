//right, its common sense bruh!

class Solution {
public:
    
    int res = 0;

    void permute(vector<int> &arr, int idx) {
        if (idx == arr.size()) res++;
        
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[i], arr[idx]);
            if (arr[idx]%(idx+1) == 0 || (idx+1)%arr[idx] == 0)
                permute(arr, idx+1);
            swap(arr[i], arr[idx]);
        }
    }
    int countArrangement(int n) {
        vector<int> arr(n);
        for (int i = 1; i <= n; i++) {
            arr[i-1] = i;
        }
        permute(arr, 0);
        return res;
    }
};