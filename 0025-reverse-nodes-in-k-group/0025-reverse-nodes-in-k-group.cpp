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
     ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* groupprev = dummy;

        while(true){
            ListNode* kth = groupprev;
            
            for(int i=0;i<k;i++){
                kth = kth->next;
                if(kth == nullptr){
                    return dummy->next;
                }
            }

            ListNode* groupnext = kth->next;
            ListNode* grouphead = groupprev->next;

            reverse(grouphead,groupnext);

            groupprev->next = kth;
            grouphead->next = groupnext;

            groupprev = grouphead;
            
        }
        return dummy->next;
    }
};