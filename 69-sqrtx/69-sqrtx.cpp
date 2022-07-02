class Solution {
public:
    int isPerfectSquare(int x)
    { 
        long long left = 1, right = x;

        while (left <= right)
        {
            long long mid = (left + right) / 2;

            if (mid * mid == x)
                return mid;
            
            if (mid * mid < x)left = mid + 1;
            
            else right = mid - 1;
            
        }
        return right;
    }
 
    int mySqrt(int x) {
        return isPerfectSquare(x);
    }
};