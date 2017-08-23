class Solution {
public:
    // Since the array is sorted, for every num, whether to keep it or not depends
    // whether it is larger than the last-1(i-2) number of the already keeped number sequence.
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto num:nums) {
            if (i < 2 || num > nums[i-2]) nums[i++] = num;
        }
        return i;
    }
};


class Solution {
public:
    // Use id to record the num of not duplicated nums or duplicates less than or equal to twicetill now.
    // id starts from 1 because the first num must be retained, and i also starts from 1.
    // Use cnt to record how many duplicates for the current number till now. (similar to problem 26)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), cnt = 1, id=1;
        if (n < 3) return n;
        for (int i = 1; i < n; i++) {
            if(nums[i]==nums[i-1]) {
                cnt++;
                if(cnt == 2) nums[id++] = nums[i];
            } else {
                cnt = 1;
                nums[id++] = nums[i];
            }
        }
        return id;
    }
};