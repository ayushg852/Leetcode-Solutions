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
        if(head==NULL)
        return NULL;
        Node* temp=head;
        while(temp)
        {
            Node* copy=new Node(temp->val);
            Node* nex=temp->next;
            temp->next=copy;
            copy->next=nex;
            temp=nex;
        }
        temp=head;
        while(temp)
        {
            if(temp->random==NULL)
            temp->next->random=NULL;
            else
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* headcopy=temp->next;
        while(temp)
        {
            Node* nex=temp->next;
            temp->next=nex->next;
            temp=temp->next;
            if(temp==NULL)
            nex->next=NULL;
            else
            nex->next=nex->next->next;
        }
        return headcopy;
    }
};