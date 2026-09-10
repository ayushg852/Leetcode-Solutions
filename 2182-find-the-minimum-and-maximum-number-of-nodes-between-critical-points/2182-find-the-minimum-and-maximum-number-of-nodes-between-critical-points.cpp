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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int last=1e7;
        int first=-1;
        ListNode* prev=head;
        head=head->next;
        vector<int> ans(2,1e8);
        int c=0;
        while(head->next)
        {
            c++;
            ListNode* nex=head->next;
            if((head->val>prev->val && head->val>nex->val) || (head->val<prev->val && head->val<nex->val))
            {
                if(first==-1)
                first=c;
                else
                ans[0]=min(ans[0],c-last);
                last=c;
            }
            prev=head;
            head=head->next;
        }
        if(first==-1||last==first)
        return {-1,-1};
        ans[1]=last-first;
        return ans;
    }
};