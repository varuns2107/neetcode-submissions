/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head;
        while(temp != NULL) {
            Node* front = temp->next;
            Node* newnode = new Node(temp->val);
            temp->next = newnode;
            newnode->next = front;
            temp = front;
        }

        temp = head;
        while(temp != NULL) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            else temp->next->random = NULL;
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* prev = dummy;
        temp = head;
        while(temp != NULL) {
            prev->next = temp->next;
            temp->next = temp->next->next;
            prev = prev->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
