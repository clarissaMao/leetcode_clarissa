class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //use id to serve as the index. If the current number not equals to
        //the val, it's a good num and assign it to nums[id].
        int id = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(nums[i]!=val) nums[id++] = nums[i];
        }
        return id;
    }
};