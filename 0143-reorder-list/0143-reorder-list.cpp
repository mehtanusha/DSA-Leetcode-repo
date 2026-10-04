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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;

        ListNode* middle = findmiddle(head);
        ListNode* second = middle->next;
        middle->next = nullptr;

        second = reverse(second);

        ListNode* p1 = head;
        ListNode* p2 = second;

        while(p2 != nullptr){
            ListNode* temp = p1->next;
            ListNode* temp2 = p2->next;

            p1->next = p2;
            p2->next = temp;

            p1 = temp;
            p2 = temp2;
        }
        return;
    }
};