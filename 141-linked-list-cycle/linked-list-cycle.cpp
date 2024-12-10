/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return 0;
        }
        ListNode* h=head;
        ListNode* h2=head;
        h=h->next;
        h2=h2->next->next;
        while(h!=NULL && h2!=NULL){
            if(h==h2){
                cout<<h->val<<" "<<h2->val<<endl;
                return true;
            }
            h=h->next;
            h2=h2->next;
            if(h2==NULL){
                break;
            }
            else{
                h2=h2->next;
            }
        }
        return false;
    }
};