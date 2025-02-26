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
            int first = 1;
            int second = min(h->val, h2->val);
            int small = min(h->val, h2->val);
            int big = max(h->val, h2->val);
            // cout<<small<<"  "<<big<<endl;
            int now=0;
            if(big%small==0){
                now = small;
            }
            else{
                now = gcd(big, small);
            }
            // cout<<now<<endl;
            ListNode* temp = new ListNode(now);
            h->next=temp;
            temp->next=h2;
            h=h2;
            h2=h2->next;
        }
        return head;
    }
};