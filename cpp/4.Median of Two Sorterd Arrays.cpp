class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // left_part          |        right_part
        //A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
        //B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
        // ensure 1) len(left_part) == len(right_part)   2) max(left_part) <= min(right_part)
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        if (n==0) return 0;
        // A could be divided into 0~m parts, so imin = 0, imax = m;
        int imin = 0, imax = m, i, j, mid = (m + n + 1) >> 1;
        double max_left = 0, min_right = 0;
        //binary search for i, i + j = m-i + n-j +1 for equal length condition
        while (imin <= imax) {
            i = (imin+imax) >> 1;
            j = mid - i;
            if( i > 0 && j < n && nums1[i-1] > nums2[j]) {   //i too big
                imax = i - 1;
            } else if (j > 0 && i < m && nums2[j-1] > nums1[i]) { // i too small
                imin = i + 1;
            } else { //just good, 4 edge condition: i = 0, j = 0, i = m, j = n.
                if (i == 0) {
                    max_left = nums2[j-1];
                } else if (j == 0) {
                    max_left = nums1[i-1];
                } else {
                    max_left = max(nums1[i-1], nums2[j-1]);
                }
                // if odd numbers of elements, return. we separate before to favor 1 more to the left.
                if ( (m+n) & 1) return max_left;
                if (i == m) {
                    min_right = nums2[j];
                } else if (j == n) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums1[i], nums2[j]);
                }
                return (max_left + min_right) / 2;
            }
        }
    }
};