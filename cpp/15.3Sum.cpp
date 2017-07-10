class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array first. In the for loop, skip those equal numbers for no duplicates.
        // Fix one number, then we'll know the sum of the other two numbers. Since the array is
        // sorted, start from two end (left and right) to find the two numbers. Also skip the equal
        // numbers in the "two end to middle" search.
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if( i==0 || (i > 0 && nums[i] != nums[i-1])) {
                int target = 0 - nums[i];
                int l = i + 1, r = n - 1;
                while (l < r) {
                    if (nums[l] + nums[r] == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        res.push_back(tmp);
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    } else if (nums[l] + nums[r] > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};