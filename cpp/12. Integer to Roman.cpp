class Solution {
public:
    string intToRoman(int num) {
        //Create 2 vectors, romans and vals, in descending order. Including chars like IV, IX.
        //use a "for" loop to traverse the vector and inside the loop use a
        //"while" statement to decrease the num gradually, start from the biggest possible value.
        string res;
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int n = vals.size();
        for(int i = 0; i < n; i++) {
            while(num >= vals[i]) {
                res += romans[i];
                num -= vals[i];
            }
        }
        return res;
    }
};