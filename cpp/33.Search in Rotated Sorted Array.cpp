class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Notice that there is always a half of the array sorted, so we only need to see
        //whether the target is in the sorted part or rotated part.
        //compare nums[mid] and nums[l] to see whether mid is in the sorted part.
        //for target, consider the range of mid and one side (left or right) togher.
        int n = nums.size();
        int l = 0, r = n-1, mid = 0;
        while (l <= r) {
            mid =l + (r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid] < nums[l]) {
                if (target >= nums[mid] && target <= nums[r]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            } else {
                if(nums[l] <= target && target <= nums[mid]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};