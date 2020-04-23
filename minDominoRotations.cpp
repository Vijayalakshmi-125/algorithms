/*

https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

*/

class Solution {
public:

    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size(); int ans=INT_MAX;
        
        for(int num=1; num<=6; num++){
            bool found=true; int ac=0, bc=0;
            for(int i=0;i<n;i++){
                if(A[i]!=num && B[i]!=num){
                    found=false;
                    break;
                }
                if(A[i]==num) ac++;
                if(B[i]==num) bc++;
                
            }
            
            if(found){
                int ca = n-max(bc,ac);
                ans=min(ans, ca);
            }
        }
        
        return (ans==INT_MAX?-1:ans);
    }
};