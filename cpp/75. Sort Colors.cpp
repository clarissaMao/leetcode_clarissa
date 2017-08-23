class Solution {
public:
    // Two pointers. i is always the index for the element which is just next to the
    // last "0" in the currrent ordered sequence while j is always the index for the
    // element which is just next to the last "1" in the current ordered sequence.
    // Traverse the vector with k, when nums[k] is 0, swap twice with nums[j] and then
    // nums[i]. When nums[k] is 1, just swap with nums[j]. Increase i and j correspondingly.
    // eg. 2 2 1 1 0 0 2
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for (int k = 0; k < n; k++) {
            if (nums[k] == 0) {
                swap(nums[k], nums[j]);
                swap(nums[j], nums[i]);
                i++;
                j++;
            } else if (nums[k] == 1) {
                swap(nums[k], nums[j]);
                j++;
            }
        }
    }
};


class Solution {
public:
    // Swap all 0s to the left and all 2s to the right, then all 1s are left in the middle.
    // Notice we first check whether the current number is 2 and then check whether it's 0.
    // This is because if 2 is swaped with 0, then we need to swap current pos again, which
    // is now 0 to the beginning. k don't need to be < n, <= j is fine.
    //eg. 1 2 0. correct: 0 1 2 (1 0 2, check pos for 0 again, then get 0 1 2)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        for (int k = 0; k <= j; k++) {
            while(nums[k] == 2 && k < j) swap(nums[k], nums[j--]);
            while(nums[k] == 0 && k > i) swap(nums[k], nums[i++]);
        }
    }
};