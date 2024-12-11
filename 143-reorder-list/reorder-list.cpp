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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){return head;}
        ListNode* temp = NULL;
        while(head != NULL){
            ListNode* head2 = head->next;
            head->next = temp;
            temp=head;
            head=head2;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //cout<<slow->val<<endl;
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        // while(slow!=NULL){cout<<slow->val<<" ";slow=slow->next;}
        // cout<<endl;
        // while(fast!=NULL){cout<<fast->val<<" ";fast=fast->next;}
        // cout<<endl;
        fast = reverseList(fast);
        
        while(slow!=NULL && fast!=NULL){
            ListNode* temp1 = slow->next;
            ListNode* temp2 = fast->next;

            slow->next=fast;
            fast->next=temp1;
            slow=temp1;
            fast=temp2;
        }





    }
};