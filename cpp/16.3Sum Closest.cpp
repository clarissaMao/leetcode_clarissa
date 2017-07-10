class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sort the vector. try to be close to target in every step.
        //shift left or right.
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if(len <= 3) return accumulate(nums.begin(), nums.end(), 0);
        int cur = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < len-2; i++) {
            int j = i+1;
            int k = len-1;
            while(j < k) {
                int res = nums[i] + nums[j] + nums[k];
                if(abs(target - res) < abs(target - cur)) {
                    cur = res;
                    if(cur == target) return cur;
                }
                res > target ? k--  : j++;
            }
        }
        return cur;
    }
};