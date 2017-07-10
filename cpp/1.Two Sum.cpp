class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //use a hashmap to record the num-ind pair. If met the second
        //num, the first must already in the hashmap.
        vector<int> res;
        unordered_map<int, int> num_ind;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int other = target - nums[i];
            if(num_ind.count(other) > 0) {
                res.push_back(num_ind[other]);
                res.push_back(i);
                return res;
            } else {
                num_ind[nums[i]] = i;
            }
        }
        return res;
    }
};