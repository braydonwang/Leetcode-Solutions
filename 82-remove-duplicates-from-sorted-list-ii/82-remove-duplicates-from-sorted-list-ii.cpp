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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* prev = NULL;
        while (right) {
            right = right->next;
            while (right && right->val == left->val) {
                right = right->next;
            }
            if (right != left->next) {
                if (prev) {
                    prev->next = right;
                    left = right;
                } else {
                    head = right;
                    left = right;
                }
            } else {
                prev = left;
                left = right;
            }
        }
        return head;
    }
};