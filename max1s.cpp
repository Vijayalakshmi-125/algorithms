/*

https://www.interviewbit.com/problems/max-continuous-series-of-1s/

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

*/

class Solution {
public:

    vector<int> maxone(vector<int> &A, int m) {
        int n = A.size();
        int wL = 0, wR = 0; int bestL = 0, bestWindow = 0; int zeroCount = 0; 
        
        while (wR < n)
        {
            if (zeroCount <= m)
            {
                if (A[wR] == 0)
                zeroCount++;
                wR++;
            }
    
            if (zeroCount > m)
            {
                if (A[wL] == 0)
                zeroCount--;
                wL++;
            }
            if (wR-wL > bestWindow)
            {
                bestWindow = wR-wL;
                bestL = wL;
            }
        }
        
        vector<int> ans;
        for (int i=0; i<bestWindow; i++)
        {
            ans.push_back(bestL+i);
        }
        return ans;
    }
};