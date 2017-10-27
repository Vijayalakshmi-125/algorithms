/*

https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list.

*/

class myComparator 
{ 
public: 
    int operator() (const ListNode* l1, const ListNode* l2) 
    { 
        return l1->val > l2->val; 
    } 
}; 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        
        priority_queue <ListNode*, vector<ListNode*>, myComparator> pq; 
        for(auto l: lists){
            if(l) pq.push(l);
        }
        
        while(!pq.empty()){
            
            ListNode* smallest = pq.top();
            pq.pop();
            
            if(smallest->next)
                pq.push(smallest->next);
            
            temp->next = smallest;
            temp = temp -> next;
        }
        
        
        return head->next;
    }
};
