/*

https://leetcode.com/problems/count-numbers-with-unique-digits/

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

*/


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0) return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        
        int sum = 91;
        int t = 9*9*8;
        int ct = 7;
       
        for(int i=3;i<=n;i++){
            sum+=t;
            t*=ct--;
        }
        
        return sum;
        
    }
};