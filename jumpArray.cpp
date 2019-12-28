/*

https://leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

*/

class Solution {
public:

    bool canJump(vector<int>& nums) {
        
        int n = nums.size(), nearest=n-1;
        if(n==0) return false;
        
        for(int i=n-2; i>=0; i--){
            int jump = i + nums[i];
            if(jump >= nearest)
                nearest = i;
        }
        
        
        return (nearest==0);
    }
};