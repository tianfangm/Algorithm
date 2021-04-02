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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ret = new ListNode(0,head);
        ListNode *prev = ret;
        
        while(n>0)
        {
            head=head->next;
            n-=1;
        }
        while(head!=nullptr)
        {
            head=head->next;
            prev = prev->next;
        }
        ListNode*temp = prev->next;
        prev->next = temp->next;
        delete temp;
        return ret->next;
    }
};
