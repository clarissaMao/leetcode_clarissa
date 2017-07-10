class Solution {
public:
    int reverse(int x) {
        // If x is negative, then both x / 10 and x % 10 is negative.
        // We don't need to use a sign to represent whether x is negative or positive.
        // Notice to judge whether it would be overflow or not before multiply it by 10.
        int result = 0;
        while(x!=0){
            if(result>INT_MAX/10 || result<INT_MIN/10) return 0;
            result = result*10+x%10;
            x=x/10;
        }
        return result;
        
    }
};