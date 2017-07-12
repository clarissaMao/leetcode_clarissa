class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //sort the vector. use break and continue wisely to avoid
        //redundant computation.
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for (int j = i + 1; j < n-2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    int total = nums[i] + nums[j] + nums[l] + nums[r];
                    if (total < target) l++;
                    else if (total > target) r--;
                    else {
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l-1]) l++;
                        while (l < r && nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        return res;
    }
};