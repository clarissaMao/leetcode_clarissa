class Solution {
public:
    bool isPalindrome(int x) {
        // A consice solution, but need to consider more edge cases. One pass.
        // Convert the right half of the number to a reversed result and compare
        // it with the left half.
        // edge cases: 1000, 2000...need to be considered ahead.
        if (x < 0 || x != 0 && x%10 ==0) return false;
        int sum = 0;
        while (sum < x) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (sum == x || x == sum/10);
    }
};



class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int num = x, lind = 0, rind = 0;
        while (num != 0) {
            rind++;
            num /= 10;
        }
        while (lind < rind) {
            int left = x / pow(10, rind-1);
            int right = x % 10;
            if (left != right) return false;
            x = (x - right - left * pow(10, rind-1)) / 10;
            rind -= 2;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int len = 1;
        int right;
        int left;
        while(x/len>=10){
            len*=10;
        }
        while(x!=0){
            right = x%10;
            left = x/len;
            if(right!=left) return false;
            x=(x%len-right)/10;
            len = len/100;
        }
        return true;
        
        
    }
};