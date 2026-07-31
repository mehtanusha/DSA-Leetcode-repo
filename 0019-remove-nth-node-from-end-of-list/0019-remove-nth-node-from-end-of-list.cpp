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
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(n!=0 && fast){
            fast = fast->next;
            n--;
        }

        if(fast == nullptr){
            ListNode* temp = head;
            head = head->next;
            return head;
        }
        ListNode* prev = nullptr;
        while(fast != nullptr){
           prev = slow;
           slow = slow->next;
           fast = fast->next;
        }

        prev->next = slow->next;
        slow->next = nullptr;
        return head;
    }
};
