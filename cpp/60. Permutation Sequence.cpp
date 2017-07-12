class Solution {
public:
    string getPermutation(int n, int k) {
        // Create two vectors num and factorial, factorial is used to store all the factorials
        // from 0! to n!, num is used to store all the remainning numbers that could be candidates.
        // for current number, we use (k-1) / factorial[i-1] + 1 to calculate the index and use num
        // to find the actural number. We use (k-1) % factorial[i-1] + 1 to calculate the next "pos"
        // for next iteration.
        //"123"  1
        //"132"  2
        //"213"  3
        //"231"  4
        //"312"  5
        //"321"  6
        string res;
        vector<int> num(n+1);
        vector<int> factorial(n+1);
        factorial[0] = 1, num[0] = 0;
        for (int i = 1; i <= n; i++) {
            num[i] = i;
            factorial[i] = factorial[i-1]*i;
        }
        for (int i = n; i > 0; i--) {
            int cur = (k-1) / factorial[i-1] + 1;
            res += to_string(num[cur]);
            num.erase(num.begin()+cur);
            k = (k-1) % factorial[i-1] + 1;
        }
        return res;
    }
};