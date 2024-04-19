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
        int total = 0;
        for (auto e:lists) while (e!=nullptr) total += 1, e = e->next;

        vector<int> allVals(total);
        int idx = 0;
        // for (auto e:lists) {
        //     while (e!=nullptr) {
        //         allVals[idx] = e->val;
        //         e = e->next;
        //         idx += 1;
        //     }
        // }
        for (auto e:lists) while (e!=nullptr) allVals[idx] = e->val, e = e->next, idx += 1;
        sort(allVals.begin(), allVals.end());

        auto head = ListNode();
        auto walker = &head;
        for (auto e:allVals) walker->next = new ListNode(e), walker = walker->next;

        return head.next;   
    }
};