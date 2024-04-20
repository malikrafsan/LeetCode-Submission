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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 && l1->val == 0) return l2;
        if (l2 && l2->val == 0) return l1;

        // long long l1Sum = 0;
        // long long l2Sum = 0;
        vector<int> l1Val;
        vector<int> l2Val;
        ListNode* res = nullptr;

        while (1) {
            if (!l1) break;

            // l1Sum *= 10;
            // l1Sum += l1->val;
            l1Val.push_back(l1->val);
            l1 = l1->next;
        }   
        while (1) {
            if (!l2) break;

            // l2Sum *= 10;
            // l2Sum += l2->val;
            l2Val.push_back(l2->val);
            l2=l2->next;
        }   

        int idx1 = l1Val.size()-1;
        int idx2 = l2Val.size()-1;

        int carryover = 0;
        while (1) {
            if (idx1 < 0 || idx2 < 0) break;

            int sum = l1Val[idx1] + l2Val[idx2] + carryover;
            res = new ListNode(sum%10, res);
            carryover = sum >= 10 ? 1 : 0;
            idx1--;
            idx2--;
        }

        while (1) {
            if (idx1 < 0) break;

            int sum = l1Val[idx1]+carryover;
            res = new ListNode(sum%10,res);
            carryover = sum >= 10 ? 1 : 0;
            idx1--;
        }

        while (1) {
            if (idx2 < 0) break;

            int sum = l2Val[idx2]+carryover;
            res = new ListNode(sum%10,res);
            carryover = sum >= 10 ? 1 : 0;
            idx2--;
        }

        if (carryover != 0) res = new ListNode(carryover, res);

        return res;

        // long long l3Sum = l1Sum + l2Sum;

        // ListNode* res = nullptr;
        // while (1) {
        //     if (l3Sum == 0) break;

        //     int residu = l3Sum %10;
        //     l3Sum = l3Sum / 10;
        //     res = new ListNode(residu, res);
        // }
        // return res;
    }
};