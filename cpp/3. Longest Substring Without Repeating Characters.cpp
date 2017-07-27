class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //use a dict to record the index of every char. If met with the same char, update it.
        //use start to point to the candidate string's start index. It should the the max of
        //start and dict[s[i]]+1 if s[i] occured for the second time.
        int n = s.size(), start = 0, length = 0;
        unordered_map<char, int> dict;
        for (int i = 0; i < n; i++) {
            if(dict.count(s[i]) > 0) {
                start = max(start, dict[s[i]]+1);
            }
            dict[s[i]] = i;
            length = max(length, i-start+1);
        }
        return length;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use a dict to record the occurence of a char. If it occurred
        // for the second time, then we traverse from previous start point
        // to now until the we find the first occurence of this char and move
        // the start to the index next to it.We calculate the new length and see
        // whether it's bigger or not.
        int n = s.size(), start = 0, length = 0;
        unordered_map<char, int> dict;
        for (int i = 0; i < n; i++) {
            dict[s[i]]++;
            while(dict[s[i]]==2) {
                dict[s[start]]--;
                start++;
            }
            length = max(length, i-start+1);
        }
        return length;
    }
};