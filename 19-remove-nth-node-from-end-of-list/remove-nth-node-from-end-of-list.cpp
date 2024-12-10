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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return head->next;
        }
        if(n==1){
            ListNode* h =head;
            while(h->next->next!=NULL){
                h=h->next;
            }
            h->next=NULL;
            return head;
        }
        
        head = reverseList(head);
        ListNode* h = head;
        ListNode* t=h;
        //cout<<head->val<<endl;
        h=h->next;n-=1;
        while(n>1){
            t=h;
            h=h->next;
            n--;
        }
        ListNode* h2 = h->next;
        cout<<t->val<<" "<<h->val<<endl;
        t->next=h2;
        h->next=NULL;
        head = reverseList(head);
        return head;
    }
};