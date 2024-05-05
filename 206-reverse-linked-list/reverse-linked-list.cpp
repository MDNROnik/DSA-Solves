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
};