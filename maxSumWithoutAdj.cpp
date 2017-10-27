/*

https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

Given a 2 x n grid of integer, A, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

*/

class Solution {
public:

    int adjacent(vector<vector<int> > &A) {

        int n = A[0].size();
        vector<vector<int> > dp( n+1 , vector<int> (2, 0));  

        dp[0][1] = max(A[0][0], A[1][0]);
        for (int i = 1; i < n; i++) {
            int curr = max(A[0][i], A[1][i]);
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = curr + dp[i-1][0];
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};