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
    ListNode* fun(ListNode* now){
        if(now->next==NULL){
            return now;
        }
        ListNode* ans = fun(now->next);
        // cout<<now->val<<" "<<ans->val<<endl;
        if(now->val < ans->val){
            return ans;
        }
        now->next=ans;
        return now;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        return fun(head);

    }
};