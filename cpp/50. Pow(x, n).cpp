class Solution {
public:
    double myPow(double x, int n) {
        // Iterative solution. Corner cases: x=1, x=-1, n=INT_MIN, n is negative.
        // But if we convert n to a long long type, we don't need to consider the situation of n=INT_MIN.
        // Since base won't overflow when changing to abs(base).
        // Speed up: use a while statement, base is x, exponent is n. x^n = (x^2)^(n/2), so
        // right shift n and square x at the same time. if n&1=1, means the result is the odd
        // number exponent of x, so we need to multiply one time of x here.
        double res = 1;
        long long base = n;
        if (base < 0) {
            x = 1/x;
            base = -base;
        }
        while (base != 0) {
            if (base&1 == 1) res*=x;
            base >>= 1;
            x *= x;
        }
        return res;
    }
};



class Solution {
public:
    double myPow(double x, int n) {
        // A recursive solution. Need to consider n = INT_MIN, if it is, then -n would
        // overflow. So we use long long p = n here.
        long long p = n;
        if (p==0 || x==1) return 1;
        if (p < 0) {
            p = -p;
            x = 1/x;
        }
        return (p % 2 == 0) ? myPow(x*x, p/2) : x*myPow(x*x, p/2);
    }
};