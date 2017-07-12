class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointers, since they move to the middle, so only stop
        // when the current height is higher than the real_height.
        int i = 0, j = height.size()-1, area = 0;
        while ( i <= j) {
            int real_height = min(height[i], height[j]);
            area = max(area, real_height * (j - i));
            while(height[i] <= real_height) i++;
            while(height[j] <= real_height) j--;
        }
        return area;
    }
};