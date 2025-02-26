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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* h=head;
        ListNode* h2=head->next;
        while (h->next != NULL){
            int now = gcd(h->val, h2->val);;
            ListNode* temp = new ListNode(now);
            h->next=temp;
            temp->next=h2;
            h=h2;
            h2=h2->next;
        }
        return head;
    }
};