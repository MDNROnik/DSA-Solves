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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        ListNode* headPre = list1;
        while(a>0){
            headPre = head;
            head = head->next;
            a--;b--;
        }
        headPre->next = list2;
        while(list2->next != NULL){
            list2=list2->next;
        }
        while(b>0){
            head = head->next;
            b--;
        }
        list2->next=head->next;
        return list1;

    }
};