/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() :
 . val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head){
       if(head == nullptr) return nullptr;
        ListNode* prev = nullptr;
        while(head){
           ListNode* currnext = head->next;
           head->next = prev;
           prev = head;
           head = currnext;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* temp = slow->next;
        slow->next = nullptr;
        ListNode* l2 =  reverse(temp);


        while(l2!=nullptr){
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;

            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    
    }
};
