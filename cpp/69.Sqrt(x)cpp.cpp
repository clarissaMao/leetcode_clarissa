class Solution {
public:
    int mySqrt(int x) {
        // Binary search. Left is initialized to 1 and right to INT_MAX. To avoid overflow,
        // mid = left + (right-left)/2, but not (right + left)/2. Also when judging whether
        // mid*mid > x, use mid > x/mid. The condition of the while is left <= right, don't
        // forget the equal.
        if (x==0||x==1) return x;
        int left = 1, right = INT_MAX;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (mid > x/mid) {
                right = mid - 1;
            } else {
                if (mid+1 > x/(mid+1)) return mid;
                left = mid + 1;
            }
        }
    }
};


class Solution {
public:
    int mySqrt(int x) {
        // Newton's method.
        long r = x;
        while (r * r > x) r = (r + x / r) / 2;
        return r;
    }
};