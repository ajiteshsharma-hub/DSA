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
    void insertInBetween(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
    }

    void getRandomPointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
            }
            else{
                copy->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    
    Node* getDeeperCopyList(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp != NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        insertInBetween(head);
        getRandomPointers(head);
        return getDeeperCopyList(head);
    }
};