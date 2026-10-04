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
    ListNode* addNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        int carry = 0;

        while(p1 != nullptr || p2 != nullptr || carry != 0){
            int sum = 0;
            if(carry != 0){
                sum = carry;
            }
            if(p1 != nullptr){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != nullptr){
                sum += p2->val;
                p2 = p2->next;
            }
            if(sum > 9){
                carry = sum /10;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            ListNode* temp = new ListNode(sum);
            prev->next = temp;
            prev = temp;
        }
        return dummy->next;
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverse(l1);
        ListNode* head2 = reverse(l2);

        ListNode* ans = addNumbers(head1,head2);
        ListNode* result = reverse(ans);
        return result;
    }
};