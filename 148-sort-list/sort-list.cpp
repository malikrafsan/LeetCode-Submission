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
    ListNode* getMid(ListNode* head) {
        auto slow = head;
        auto fast = head->next;

        while (1) {
            if (!fast || !fast->next) break;

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left || !right) return right;

        auto ans = new ListNode(-1);
        auto tmp = ans;

        while (1) {
            if (!left | !right) break;

            if (left->val < right->val) {
                tmp->next = left;
                tmp = left;
                left = left->next;
            } else {
                tmp->next = right;
                tmp = right;
                right = right->next;
            }
        }

        while (1) {
            if (!left) break;
            tmp->next = left;
            tmp = left;
            left = left->next;
        }
        while (1) {
            if (!right) break;
            tmp->next = right;
            tmp = right;
            right = right->next;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        auto middle = getMid(head);

        auto left = head;
        auto right = middle->next;
        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};