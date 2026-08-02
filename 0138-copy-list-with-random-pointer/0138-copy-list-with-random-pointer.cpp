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
        if(head == nullptr) return nullptr;
        unordered_map<Node*,Node*> mp;
        
        Node* prev = nullptr;
        Node* curr = head;
        Node* newHead = nullptr;
        while(curr){
            Node* temp = new Node(curr->val);
            mp[curr] = temp;

            if(newHead == nullptr){
                newHead = temp;
                prev = newHead;
            }else{
                prev->next = temp;
                prev = temp;;
            }
            curr = curr->next;
        }

        //fill random pointers

        curr = head;
        Node* newcurr = newHead;

        while(curr){
            if(curr->random == nullptr){
                newcurr->random = nullptr;
            }
            else{
                newcurr->random = mp[curr->random];
            }
            curr = curr->next;
            newcurr = newcurr->next;
        }
        return newHead;
    }
};