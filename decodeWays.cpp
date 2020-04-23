/*

https://leetcode.com/problems/decode-ways/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        if(n==0) return 0;
        if(s[0] == '0') return 0;
        if(n==1) return 1;
        
        int p1=1, p2=1, ans=0, d1=0, d2=0;
        
        for(int i=1; i<n; i++){
            ans = 0;
            
            d1 = s[i]-'0';
            d2 = (s[i-1]-'0')*10 + d1;
            
            if(d1 >= 1)
                ans += p2;
            
            if(d2 >= 10 && d2 <= 26)
                ans += p1;
            
            p1=p2; p2=ans;
        }
        
        return ans;
    }
};
