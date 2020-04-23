/*

https://leetcode.com/problems/word-break/

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

*/

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wset(wordDict.begin(), wordDict.end());
        
        vector<bool> dp(n+1, false);
        
        vector<int> ti; ti.push_back(0);
        dp[0] = true;
        
        
        for(int i=1; i<=n; i++){
            for(int j=ti.size()-1; j>=0; j--){
                int ji = ti[j];
                string word = s.substr(ji, i-ji);
                if(wset.find(word) != wset.end()){
                    dp[i] = true;
                    ti.push_back(i);
                    break;
                }
            }
        }
        
        
        return dp[n];
    }
};