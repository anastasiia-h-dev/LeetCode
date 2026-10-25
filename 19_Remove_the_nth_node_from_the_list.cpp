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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;

        int tail = 0;
        while(curr != nullptr)
        {
            curr = curr->next;
            tail++;
        }

        if(tail == n)
        {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        curr = head;
        for(int i = 0; i < tail - n - 1; i++)
        {
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        
        return head;

    }
};