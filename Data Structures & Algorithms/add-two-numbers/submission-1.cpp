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
        if(l1 == NULL && l2 == NULL) return NULL;
        else if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        int carry = 0; 
        int sum = 0;
        while(temp1 != NULL || temp2 != NULL || carry != 0) {
            sum = carry;
            if(temp1 != NULL) {
                sum += temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL) {
                sum += temp2->val;
                temp2=temp2->next;
            }
            carry = sum/10;
            sum = sum % 10;
            ListNode* newnode = new ListNode(sum);
            prev->next = newnode;
            prev = newnode;
        }
        if(carry != 0) {
            ListNode* newnode = new ListNode(1);
            prev->next = newnode;
        }
        return dummy->next;
    }
};
