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
};