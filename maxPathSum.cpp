/*

https://leetcode.com/problems/binary-tree-maximum-path-sum/

Given a non-empty binary tree, find the maximum path sum.

*/

class Solution {
public:
    int maxPath(TreeNode* root, int &res){
        if(root==NULL) return 0;
        
        int l = maxPath(root->left,res);
        int r = maxPath(root->right,res);
        
        int ms = max(max(l,r)+root->val, root->val);
        int mt = max(ms,l+r+root->val);
        res = max(res,mt);
        
        return ms;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPath(root,res);
        return res;
    }
};