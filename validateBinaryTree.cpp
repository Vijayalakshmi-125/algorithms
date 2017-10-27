/*

https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
 
 */

class Solution {
public:
    
    bool isValidTree(TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;
        
        return 
            minVal<root->val && root->val<maxVal &&
            isValidTree(root->left, minVal, (long long)root->val) &&
            isValidTree(root->right, (long long)root->val, maxVal); 
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isValidTree(root->left, (long long)INT_MIN-1, (long long)root->val) 
            && isValidTree(root->right, (long long)root->val, (long long)INT_MAX+1);
    }
};