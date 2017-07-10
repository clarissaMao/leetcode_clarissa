class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge cases: divisor = 0,dividend is INT_MIN and divisor = -1, will overflow.
        // Judge the sign first and convert the dividend and divisor to labs(the abs of INT_MIN will overflow).
        
        // Let's get started. We subtract 3 from 15 and we get 12, which is positive.
        // Let's try to subtract more. Well, we shift 3 to the left by 1 bit and we get 6.
        // Subtracting 6 from 15 still gives a positive result. Well, we shift again and get 12.
        // We subtract 12 from 15 and it is still positive. We shift again, obtaining 24 and we know we can at most
        // subtract 12. Well, since 12 is obtained by shifting 3 to left twice, we know it is 4 times of 3.
        // How do we obtain this 4? Well, we start from 1 and shift it to left twice at the same time. We add 4 to an answer             // (initialized to be 0). In fact, the above process is like 15 = 3 * 4 + 3.
        // We now get part of the quotient (4), with a remainder 3.
        // multiply is like: 1->2->4->8->16...
        
        // Then dividend - tmp and start the new while iteration again.
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        int res = 0;
        long long divd = labs(dividend);
        long long divs = labs(divisor);
        while (divd >= divs) {
            int multiply = 1;
            long long tmp = divs;
            while (divd >= tmp << 1) {
                multiply <<= 1;
                tmp <<= 1;
            }
            divd -= tmp;
            res += multiply;
        }
        return sign*res;
    }
};