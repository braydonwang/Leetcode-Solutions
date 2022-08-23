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
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head;
        ListNode *prev = NULL; 
        ListNode *next = NULL; 
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *forward = head;
        ListNode *mid = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            mid = mid->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        mid = reverse(mid);
        while (mid != NULL && forward != NULL) {
            if (mid->val != forward->val) {
                return false;
            }
            mid = mid->next;
            forward = forward->next;
        }
        return true;
    }
};