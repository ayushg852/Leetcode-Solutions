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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL||head->next==NULL)
        return head;
        int size=1;
        ListNode* tail=head;
        while(tail->next)
        {
            size++;
            tail=tail->next;
        }
        tail->next=head;
        tail=head;
        k%=size;
        k=size-k;
        while(k-->1)
        {
            tail=tail->next;
        }
        head=tail->next;
        tail->next=NULL;
        return head;
    }
};













