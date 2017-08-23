class Solution {
public:
    string minWindow(string s, string t) {
        //use a vector (length 128, Ascii table size) to record the occurence of chars in t. Use counter to record
        //total numbers of chars needed to match. Then scan string s, increase right pointer, if met with a candidate
        //matching char, decrease counter. When counter = 0, past scanned substring contains a pattern. Use a while statement
        //to find the beginning index of the pattern in string s. For the vector, Only the index for the chars in t will be
        //0 now. If met one, increase counter, jump out of the "while" and now know the beginning index.
        vector<int> map(128,0);
        string res;
        int slen = s.size();
        int counter = t.size();
        int head = 0, begin = 0, end = 0, min_len=INT_MAX;
        for (auto c:t) map[c]++;
        for (end = 0; end < slen; end++) {
            if(map[s[end]]>0) counter--;
            map[s[end]]--;
            while(counter==0) {
                if(end-begin < min_len) {
                    min_len = end-begin+1;
                    head = begin;
                }
                if(map[s[begin]]==0) {
                    counter++;
                }
                map[s[begin]]++;
                begin++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(head, min_len);
    }
};