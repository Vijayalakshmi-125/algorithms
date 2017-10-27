/*

https://leetcode.com/problems/2-keys-keyboard/

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
 

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

*/

class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n==0 || n==1) return 0;
        if(n==2 || n==3) return n;
        
        vector<int> s;
        for(int i=1;i<=n/2;i++){
            if(n%i == 0) s.push_back(solve(i,dp)+n/i);
        }
        dp[n] = *min_element(s.begin(),s.end());
        return dp[n];
    }
    
    
    int minSteps(int n) {
        vector<int> dp(n+1);
        return solve(n,dp);
        
    }
};