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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* next = cur->next;
            if (prev) {
                prev->next = next;
                cur->next = next->next;
                next->next = cur;
            } else {
                cur->next = next->next;
              next->next = cur;
                head = next;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};