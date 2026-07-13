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
    ListNode* middlenode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* temp = head;
        ListNode* middle = middlenode(head);
        ListNode* front = middle->next;
        middle->next = NULL;

        front = reverse(front);
        
        while(front != NULL) {
            ListNode* temp1 = temp->next;
            ListNode* temp2 = front->next;
            
            temp->next = front;
            front->next = temp1;

            temp = temp1;
            front = temp2;
        }
    }
};
