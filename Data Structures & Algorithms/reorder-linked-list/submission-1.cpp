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
    void reorderList(ListNode* head) {

        // find mid
        ListNode* left = head;
        ListNode* right = head;
        while(right->next != NULL && right->next->next != NULL){
            left = left->next;
            right = right->next->next;
        }
        // reverse second half
        ListNode* second = left->next;
        left->next = NULL;

        ListNode* prev = NULL;
        while(second != NULL){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        // merge
        ListNode* first = head;
        second = prev;
        while(second != NULL){
            ListNode* firstnext = first->next;
            ListNode* secondnext = second->next;

            first->next = second;
            second->next = firstnext;

            first = firstnext;
            second = secondnext;
        }
    }
};
