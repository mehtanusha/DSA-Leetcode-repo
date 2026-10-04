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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* middle = findmiddle(head);
        ListNode* second = middle->next;
        middle->next = nullptr;

        second = reverse(second);

        int ans = 0;

        ListNode* p1 = head;
        ListNode* p2 = second;

        while(p2 != nullptr){
            int sum = p1->val + p2->val;
            ans = max(sum,ans);

            p1 = p1->next;
            p2 = p2->next;
        }
        return ans;
    }
};