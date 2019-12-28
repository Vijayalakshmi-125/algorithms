/*

https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

Given preorder and inorder traversal of a tree, construct the binary tree.

*/


class Solution {
public:

    TreeNode* build(vector<int> &inorder, vector<int> &preorder, int is, int ie, int ps, int pe)
    {
        
        if(ps > pe){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[ps]);
        int pos;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        int size = pos - is;
        node->left = build(inorder, preorder, is, pos - 1, ps + 1, ps + size);
        node->right = build(inorder, preorder,  pos + 1, ie, ps + size + 1, pe);
        return node;
        
    }

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }

};