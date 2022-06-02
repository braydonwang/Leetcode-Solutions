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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        while (lists.size() > 1) {
            ListNode* a = lists[0];
            ListNode* b = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(mergeTwo(a,b));
        }
        return lists[0];
    }
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        if (!a && !b) {
            return NULL;
        }
        ListNode* ret = new ListNode();
        ListNode* og = ret;
        while (a || b) {
            if (a && b) {
                if (a->val < b->val) {
                    ret->val = a->val;
                    a = a->next;
                } else {
                    ret->val = b->val;
                    b = b->next;
                }
            } else if (a) {
                ret->val = a->val;
                a = a->next;
            } else {
                ret->val = b->val;
                b = b->next;
            }
            if (a || b) {
                ListNode* temp = new ListNode();
                 ret->next = temp;
                  ret = temp;
            }
        }
        return og;
    }
};