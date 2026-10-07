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
    void insertcopynodes(Node* head){
        Node* temp = head;
        while(temp!=nullptr){
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;
            if(temp->next!=nullptr)
            temp = temp->next->next;
        }
    }
    void connectrandompointers(Node* head){
        Node* temp = head;
        while(temp!=nullptr){
            Node* copynode = temp->next;
            if(temp->random){
                copynode->random = temp->random->next;
            }
            else{
                copynode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* getdeepcopylist(Node* head){
        Node* dummynode = new Node(-1);

        Node* res = dummynode;
        Node* temp = head;
        while(temp!=nullptr){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;     
            }
            return dummynode->next;
    }

    Node* copyRandomList(Node* head){
        if(head==nullptr){
            return head;
        }
        insertcopynodes(head);
        connectrandompointers(head);
        return getdeepcopylist(head);
    }
};