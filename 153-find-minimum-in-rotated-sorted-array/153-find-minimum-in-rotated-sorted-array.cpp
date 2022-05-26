class Solution {
public:
    int findMin(vector<int>& a) {
        int mid, prev, next;
        int high = a.size()-1, low=0;
        int n = high-low+1;
        
        while(low <= high)
        {
            if(a[low] <= a[high])
            {
                return a[low];
            }
            mid = low + (high-low)/2;
            prev = (mid+n-1)%n;
            next = (mid+1)%n;
            if(a[mid] <= a[prev] && a[mid] <= a[next])
            {
                return a[mid];
            }
            else if(a[low] <= a[mid])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return -1;
    }
};