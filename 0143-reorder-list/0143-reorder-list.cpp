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
    ListNode* reverse(ListNode* head){
        if(!head) return NULL;

        ListNode* curr=NULL;

        while(head != NULL){
            ListNode* t = head;
            head = head->next;
            t->next=curr;
            curr = t;
        }
        return curr;
    }


    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;

        ListNode* first=head;

        while(head2 != NULL){
            ListNode* t1 = first->next;
            ListNode* t2 = head2->next;

            first->next = head2;
            head2->next = t1;

            first = t1;
            head2 = t2;
        }
    }
};