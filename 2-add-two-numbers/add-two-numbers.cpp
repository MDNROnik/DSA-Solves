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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t = new ListNode(0);
        ListNode* head = t;
        int temp = 0;
        while(l1!=NULL && l2!=NULL){
            temp+=l1->val;
            temp+=l2->val;
            int remainder = temp%10;
            temp = temp/10;
            ListNode* t2 = new ListNode(remainder);
            t->next=t2;
            t=t->next;
            l1=l1->next;l2=l2->next;
        }
        while(l1!=NULL){
            temp+=l1->val;
            int remainder = temp%10;
            temp = temp/10;
            ListNode* t2 = new ListNode(remainder);
            t->next=t2;
            t=t->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            temp+=l2->val;
            int remainder = temp%10;
            temp = temp/10;
            ListNode* t2 = new ListNode(remainder);
            t->next=t2;
            t=t->next;
            l2=l2->next;
        }
        if(temp>0){
            ListNode* t2 = new ListNode(temp);
            t->next=t2;
            t=t->next;
            t->next=NULL;
        }
        return head->next;
    }
};