class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //use id to record the num of not duplicated nums till now.
        //id starts from 1 because the first num must be retained, and i also starts from 1.
        int n = nums.size();
        if (n < 2) return n;
        int id = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i]!=nums[i-1]) nums[id++] = nums[i];
        }
        return id;
    }
};