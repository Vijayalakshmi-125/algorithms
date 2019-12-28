/*

https://leetcode.com/problems/contiguous-array/

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

*/

class Solution {
public:

    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hM; 
  
        int sum = 0, n = nums.size(); 
        int max_len = 0;
        int ending_index = -1; 
    
        for (int i = 0; i < n; i++) 
            nums[i] = (nums[i] == 0)? -1: 1; 
    
        for (int i = 0; i < n; i++) 
        { 
            sum += nums[i]; 
    
            if (sum == 0) 
            { 
                max_len = i + 1; 
                ending_index = i; 
            } 
    
            if (hM.find(sum + n) != hM.end()) 
            { 
                if (max_len < i - hM[sum + n]) 
                { 
                    max_len = i - hM[sum + n]; 
                    ending_index = i; 
                } 
            } 
            else
                hM[sum + n] = i; 
        } 
    
        for (int i = 0; i < n; i++) 
            nums[i] = (nums[i] == -1)? 0: 1; 
    
        return max_len; 
        }
};