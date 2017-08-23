class Solution {
public:
    // Use a map with a priority_queue in it. Traverse the numbers, for current num, if we can find
    // num-1 in the map, we can append it to that sequence like greedy algorithm. Priority queue stores
    // the current sizes for the sequences whose last (current biggest) number is num. If we cannot find
    // num-1, we start a new sequence, and increase flag to show we need more number for this sequence.
    // If the size for a sequence reaches 3, we decrease flag to show for this sequence, we are done.
    // At last, check flag.
    bool isPossible(vector<int>& nums) {
        int flag = 0;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> prev;
        if (nums.size() < 3) return false;
        for (auto num:nums) {
            if(prev[num-1].empty()) {
                prev[num].push(1);
                flag++;
            } else {
                int cnt = prev[num-1].top();
                cnt++;
                prev[num-1].pop();
                prev[num].push(cnt);
                if (cnt == 3) flag--;
            }
        }
        return flag==0;
    }
};



class Solution {
public:
    // Use two maps. freq is used to store the frequency for all the numbers. append is used to
    // indicate that the current number could be appended to one of the previous sequences.
    // for current num, if freq[num]=0, all the num are used, skip the num. If append[num] > 0,
    // we can append it to a previous sequence, append[num]-- and num+1 could then be appended
    // to that sequence, so append[num]++. If we can find remaining num+1 and num+2 in freq,
    // we can start a new sequence, and may append num+3 afterwards. If it statisfies none of the
    // situation, return false.
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, append;
        for (auto num:nums) freq[num]++;
        for (auto num:nums) {
            if (freq[num]==0) continue;
            else if (append[num] > 0) {
                append[num]--;
                append[num+1]++;
            } else if(freq[num+1] > 0 && freq[num+2] > 0) {
                freq[num+1]--;
                freq[num+2]--;
                append[num+3]++;
            } else {
                return false;
            }
            freq[num]--;
        }
        return true;
    }
};