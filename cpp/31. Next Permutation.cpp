class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1,5,4,3,2->2,1,3,4,5  how? find pivot 5, order 5,4,3,2->2,3,4,5, then swap 1 and 2
        //5,1,1->1,1,5 the last one to the first one, just sort the whole vector.
        //upper_bound: find the first number in the range that is larger than the current num.
        int n = nums.size();
        for (int i = n-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                sort(nums.begin()+i, nums.end());
                auto it = upper_bound(nums.begin()+i, nums.end(), nums[i-1]);
                swap(nums[it-nums.begin()], nums[i-1]);
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};