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
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return head;
        }
        ListNode* prev=head;
        ListNode* pres=head->next;
        prev->next=NULL;
        while(pres != NULL){
            ListNode* futu=pres->next;
            // prev pres futu
            pres->next=prev;
            prev=pres;
            pres=futu;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        ListNode* newhead= reverseList(slow->next);
        ListNode* future = newhead;
        ListNode* temp=head;
        while(newhead!=NULL){
            if(temp->val != newhead->val){
                reverseList(future);
                return false;
            }
            temp=temp->next;
            newhead=newhead->next;
        }
        reverseList(future);
        return true;

    }
};