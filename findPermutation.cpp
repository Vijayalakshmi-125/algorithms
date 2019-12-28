/*

https://www.interviewbit.com/problems/find-permutation/

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

*/

class Solution {
public:

    vector<int> findPerm(const string A, int B) {
        int mn = 1, n=A.size(), mxn = B;
        vector<int> ans;
        
        for(int i=0; i<B && mn < mxn; i++){
            if(A[i] == 'I'){
                ans.push_back(mn); 
                mn++;
            }
            else{
                ans.push_back(mxn);
                mxn--;
            }
        }
        
        ans.push_back(mn);  
        return ans;
    }
};