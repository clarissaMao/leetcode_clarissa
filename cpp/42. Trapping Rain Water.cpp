class Solution {
public:
    int trap(vector<int>& height) {
        // Use two pointers. store two variables, maxleft and maxright.
        // every time when the height for the current left index is smaller
        // than the value of maxleft, and if the right side could make it
        // not leak (height[right] >= height[left] at this time), the trapped water
        // would increase by maxleft-height[left]. The right side is symmetric.
        int left = 0, right = height.size() -1;
        if (right <= 0) return 0;
        int maxleft = 0, maxright = 0;
        int cnt = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (maxleft < height[left]) {
                    maxleft = height[left];
                } else {
                    cnt += maxleft - height[left];
                }
                left++;
            } else {
                if (maxright < height[right]) {
                    maxright = height[right];
                } else {
                    cnt += maxright - height[right];
                }
                right--;
            }
        }
        return cnt;
    }
};