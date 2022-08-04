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
    ListNode* partition(ListNode* head, int x) {
        ListNode fst = ListNode(0), snd = ListNode(0);
        ListNode* lst1 = &fst;
        ListNode* lst2 = &snd;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                lst1->next = cur;
                lst1 = lst1->next;
            } else {
                lst2->next = cur;
                lst2 = lst2->next;
            }
            cur = cur->next;
        }
        lst1->next = snd.next;
        lst2->next = NULL;
        return fst.next;
    }
};