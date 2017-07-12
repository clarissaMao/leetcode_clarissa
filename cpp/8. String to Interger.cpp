class Solution {
public:
    int myAtoi(string str) {
        // +-10, ++10, --10 all return 0 because they are not correct.
        // First skip all blank spaces, and then judge whether the number is positive or negative.
        // Traverse the remaining numbers and consider the situatino of overflow.
        int n = str.size();
        if(n==0) return 0;
        int res = 0, i = 0, sign=1;
        bool flag=false;
        while (str[i]==' ') i++;
        while (str[i]=='+'||str[i]=='-') {
            if (flag) return 0;
            sign = str[i++]=='-' ? -1 : 1;
            flag = true;
        }
        while (i < n && str[i] >='0' && str[i] <= '9') {
            if (res > INT_MAX/10 || (res == INT_MAX/10 && str[i] > '7')) {
                if (sign ==1) return INT_MAX;
                return INT_MIN;
            }
            res = res*10 + str[i++]-'0';
        }
        return res*sign;
    }
};