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
        ListNode *node = head;
        int size = 0;
        while (node) {
            size++;
            node = node->next;
        }
        n = size - n;
        node = head;
        ListNode *prev = NULL;
        while (n) {
            prev = node;
            node = node->next;
            n--;
        }
        if (!prev) {
            return node->next;
        }
        prev->next = node->next;
        return head;
    }
};