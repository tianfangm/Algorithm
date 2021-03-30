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
    pair<ListNode*,ListNode*> reverseK(ListNode* head , ListNode* tail)
    {
        ListNode*prev = tail->next,*cur = head;
        while(prev!=tail)
        {
            ListNode*temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return {tail,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*pHead = new ListNode(),*cur = pHead;
        pHead->next = head;
        while(head)
        {
            int i = 1;
            ListNode*tail = head;
            while(tail&&i<k)
            {   
                tail = tail->next;
                i+=1;
            }
            if(!tail)
            {
                break;
            }
            pair<ListNode*,ListNode*> result = reverseK(head,tail);
            cur->next = result.first;
            cur = result.second;
            head = cur->next;
        }

        return pHead->next;
    }
};
