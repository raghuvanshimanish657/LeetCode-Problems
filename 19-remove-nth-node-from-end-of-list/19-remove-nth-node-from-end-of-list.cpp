/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(-1); // dummyptr to go just before the nth node
        dummy->next=head; //connect dummy just before  head.
        ListNode*fast=dummy;
        ListNode*slow=dummy;
        for(int i=0;i<n;++i){
            fast=fast->next;    //First Move fast ptr to n positions.
        }      //Intuition-Now fast will always be n positions after the slow ptr
        while(fast->next!=NULL){
            slow=slow->next; //Move fast to null with slow
            fast=fast->next;
        }
        slow->next=slow->next->next; //remove that node from LL
        return dummy->next;
    }
};