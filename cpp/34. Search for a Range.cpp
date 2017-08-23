class Solution {
public:
    // Use binary search to find one of the target numbers. Then start form this index,
    // search to left side and right side until reach the most left number and most right
    // number which equal to target.
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        int l = 0, r = n-1, ind=-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                ind = mid;
                break;
            } else if (nums[mid ] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ind==-1) return vector<int>{-1, -1};
        int lind = ind-1, rind = ind+1;
        while (lind >= 0 && nums[lind] == target || rind < n && nums[rind] == target) {
            if (lind >= 0 && nums[lind] == target) lind--;
            if (rind < n && nums[rind] == target) rind++;
        }
        res.push_back(lind+1);
        res.push_back(rind-1);
        return res;
    }
};