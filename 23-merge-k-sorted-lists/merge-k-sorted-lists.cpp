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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* head = new ListNode(-100000);
        head->next = lists[0];

        for(int i=1;i<lists.size();i++){
            ListNode* t = lists[i];
            ListNode* p = head;
            ListNode* c = head->next;

            while(t!=NULL && c!=NULL){
                if(t->val <= c->val){
                    p->next=t;
                    p=p->next;
                    t=t->next;
                    p->next=c;
                }
                else{
                    c=c->next;
                    p=p->next;
                }
            }
            while(t!=NULL){
                ListNode* now = p->next;
                p->next = t;
                t=t->next;
                p=p->next;
                p->next=now;
            }
        }
        head=head->next;
        return head;
    }
};