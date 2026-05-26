/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head){
        ListNode *temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp= temp->next;
        }
        return cnt;
    }

    ListNode *collisionPoint(ListNode *t1, ListNode *t2, int d){
        while(d != 0){
            d--;
            t2 = t2->next;
        }
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int n1 = getLength(headA);
        int n2 = getLength(headB);
        int d;
        if(n1 < n2){
            d = n2 - n1;
            return collisionPoint(t1, t2, d);
        }
        else{
            d = n1 - n2;
            return collisionPoint(t2, t1, d);
        }
        return NULL;
    }
};