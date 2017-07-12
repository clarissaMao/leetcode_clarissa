class Solution {
public:
    bool isNumber(string s) {
        // DFA. Erase the prefix and postfix blank space first. for dot, we need to check whether
        // digits appear before or after to give the final bool judgement.
        
        int state = 0, flag = 0, n = s.size();
        if (n == 0) return false;
        while (s[0]==' ') s.erase(0,1);
        while (s[s.size()-1] == ' ') s.erase(s.size()-1, 1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                flag = 1;
                if (state <= 2) state = 2;
                else (state <= 5) ? state = 5 : state = 7;
            } else if (s[i] == '+' || s[i] == '-') {
                if (state == 0 || state == 3)state += 1;
                else return false;
            } else if (s[i] == '.') {
                if (state <= 2) state = 6;
                else return false;
            } else if (s[i] == 'e') {
                if (flag && (state == 2 || state == 6 || state == 7)) state = 3;
                else return false;
            } else {
                return false;
            }
        }
        return (state == 2 || state == 5 || flag && state == 6 || state == 7);
        
    }
};