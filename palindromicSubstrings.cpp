/*

https://leetcode.com/problems/palindromic-substrings/

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

*/


class Solution {
public:
    
    int countSubstrings(string s) {
        vector<vector<bool> >d(s.length(), vector<bool>(s.length(), true));
        int count = s.length();
        for(int l = 2; l <= s.length(); l++)
            for(int i = 0; i + l - 1 < s.length(); i++ )
                d[i][i+l-1] = (s[i] == s[i+l-1]) && (i+1 > i+l-2 || d[i+1][i+l-2]) && count++;
        return count;
    }   
};