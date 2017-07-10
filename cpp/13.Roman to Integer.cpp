class Solution {
public:
    // write a small function to convert roman char to one digit.
    // for every index, compare the num that current index char represents
    // with that represented by the next right index. If left < right, like
    // IV, IX, we should deduct left: I. If left >= right, like VI, XI, we should add left: V, X.
    int charToInt (char c) {
        int res = 0;
        switch (c) {
            case 'I': res = 1;
                break;
            case 'V': res = 5;
                break;
            case 'X': res = 10;
                break;
            case 'L': res = 50;
                break;
            case 'C': res = 100;
                break;
            case 'D': res = 500;
                break;
            case 'M': res = 1000;
                break;
        }
        return res;
    }
    
    int romanToInt(string s) {
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n-1; i++) {
            int left = charToInt(s[i]);
            int right = charToInt(s[i+1]);
            if (left < right) num -= left;
            else num += left;
        }
        num += charToInt(s[n-1]);
        return num;
    }
};