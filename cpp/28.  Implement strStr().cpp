class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for (int i = 0;; i++) {
            for (int j = 0;; j++) {
                if (j==n) return i;
                if (i+j == m) return -1;
                if (needle[j] != haystack[i+j]) break;
            }
        }
    }
};


class Solution {
public:
    // kmp algorithm. Create a vector "next" to record the number of same prefix and postfix before(not including)
    // the current index. If the current haystack[i] and needle[j] matches, increase i, j and continue. If not, decrease
    // j to next[j] in order to try to find a shorter pattern which might match the haystack (move j - next[j]). Notice
    // the situation when j equals to -1.
    // http://blog.csdn.net/v_july_v/article/details/7041827
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        if (needle.length()==0) return 0;
        if (m==0) return -1;
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        while (i < m) {
            if (j==-1 || haystack[i]==needle[j]) {
                i++;
                j++;
                if (j==needle.length()) return i-j;
            } else {
                j = next[j];
            }
        }
        return -1;
    }
    
    vector<int> getNext(string needle) {
        int n = needle.length();
        vector<int> next(n);
        next[0] = -1;
        int i = 0, j = -1;
        while (i + 1 < n) {
            if (j==-1 || needle[i]==needle[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }
    
};