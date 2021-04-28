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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = new ListNode(),*pHead = head;
        int carry=0;
        while(l1&&l2)
        {
            l1->val+=l2->val+carry;
            carry = (l1->val)/10;
            l1->val%=10;
            head->next = l1;
            l1=l1->next;
            l2=l2->next;
            head = head->next;
        }
        while(l1)
        {
            l1->val+=carry;
            carry = (l1->val)/10;
            l1->val%=10;
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        while(l2)
        {
            l2->val+=carry;
            carry = (l2->val)/10;
            l2->val%=10;
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        if(carry)
        {
            head->next = new ListNode(carry);
            head = head->next;
        }
        head->next = nullptr;
        return pHead->next;
    }
};
