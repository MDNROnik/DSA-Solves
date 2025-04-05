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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = head;
        while(fast != NULL){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        last->next = NULL;
        ListNode* temp = NULL;
        ListNode* temp2 = slow->next;
        while(1){
            slow->next = temp;
            temp = slow;
            slow = temp2;
            if(slow==NULL){
                break;
            }
            temp2 = slow->next;
        }
        // last->next = temp;
        // while(head != NULL){
        //     cout<<head->val<<endl;
        //     head=head->next;
        // }
        // cout<<endl;
        // while(temp != NULL){
        //     cout<<temp->val<<endl;
        //     temp=temp->next;
        // }
        last = temp;

        int ans = -1;

        while(head!=NULL){
            int now = head->val+temp->val;
            ans = max(now, ans);
            head=head->next;
            temp=temp->next;
        }
        return ans;
    }
};