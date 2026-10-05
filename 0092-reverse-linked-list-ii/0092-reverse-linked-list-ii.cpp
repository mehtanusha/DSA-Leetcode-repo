class Solution {
public:

    ListNode* reverse(ListNode* left, ListNode* right) {
        ListNode* curr = left;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        right->next = prev;

        return right;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        if (left == right) {
            return head;
        }

        ListNode* curr = head;
        ListNode* lefttail = nullptr;
        ListNode* revhead = nullptr;
        ListNode* revtail = nullptr;
        ListNode* righthead = nullptr;

        int l = left;
        int r = right;

        while (curr != nullptr && r > 1) {

            if (l == 2) {
                lefttail = curr;
                revhead = curr->next;
            }

            curr = curr->next;
            l--;
            r--;

            if (r == 1) {
                revtail = curr;
                righthead = curr->next;
            }
        }

        // left == 1 case
        if (left == 1) {
            revhead = head;
            revtail = curr;
            righthead = curr->next;

            ListNode* newhead = reverse(revhead, revtail);

            revhead->next = righthead;

            return newhead;
        }

        lefttail->next = nullptr;
        revtail->next = nullptr;

        ListNode* newhead = reverse(revhead, revtail);

        lefttail->next = newhead;
        revhead->next = righthead;

        return head;
    }
};