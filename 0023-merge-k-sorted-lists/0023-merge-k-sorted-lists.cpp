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
    struct compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        for(int i=0;i<n;i++){
            if(lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            curr->next = temp;
            curr = temp;

            if(temp->next != nullptr){
                pq.push(temp->next);
            }
        }
        return dummy->next;
    }
};