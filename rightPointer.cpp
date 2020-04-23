/*

https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

*/

class Solution {
public:

    void connect(TreeLinkNode* A) {
        if(A==NULL)
            return;
        
        queue<TreeLinkNode*> q;
        q.push(A);
        
        while(1){
            int n = q.size();
            if(n==0) return;
            
            while(n--){
                TreeLinkNode* t = q.front(); q.pop();
                if(n!=0){
                    TreeLinkNode* t2 = q.front();
                    t->next = t2;
                }
                else {
                    t->next = NULL;
                }
    
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
    }
};