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
        ListNode head(-1, nullptr);
        ListNode* walker = &head;

        while(1) {
            int idxMax = -1;
            for (int i=0;i<lists.size();i++) {
                auto elmt = lists[i];
                if (elmt == nullptr) continue;

                if (idxMax == -1 || elmt->val < lists[idxMax]->val) {
                    idxMax = i;
                }
            }

            if (idxMax == -1) break;
            walker->next = lists[idxMax];
            lists[idxMax] = lists[idxMax]->next;
            walker = walker->next;
        }
        return head.next;
    }
};