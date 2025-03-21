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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* now = ans;
        int sum=0,zero=0;
        while(head!=NULL){
            if(head->val==0){zero++;}
            if(zero==1){
                sum+=head->val;
            }
            else if(zero==2){
                now->next = new ListNode(sum);
                now=now->next;
                sum=0;
                zero=1;
            }
            head = head->next;
        }
        ans=ans->next;
        return ans;
    }
};