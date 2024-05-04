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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 =  list1;
        ListNode* head2 =  list2;
        ListNode* head = new ListNode(-1);
        ListNode* h=head;
        while( head1 != NULL && head2 != NULL ){
            if(head1->val==head2->val){
                head->next=head1; head=head->next; head1=head1->next;
                head->next=head2; head=head->next; head2=head2->next;
            }
            else if(head1->val < head2->val){
                head->next=head1; head=head->next; head1=head1->next;
            }
            else{
                head->next=head2; head=head->next; head2=head2->next;
            }
        }

        while( head1 != NULL  ){
            head->next=head1; head=head->next; head1=head1->next;
        }

        while( head2 != NULL  ){
            head->next=head2; head=head->next; head2=head2->next;
        }
        h=h->next;
        return h;
    }
};