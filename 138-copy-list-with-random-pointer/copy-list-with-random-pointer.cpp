/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<int> arr;
        Node* oriHead = head;

        while (1) {
            if (!head) break;

            arr.push_back(head->val);
            head->val = arr.size()-1;
            head = head->next;
        }

        head = oriHead;
        vector<Node*> tmp;
        while (1) {
            if (!head) break;

            int idx = head->val;
            auto add = new Node(arr[idx]);
            tmp.push_back(add);
            head = head->next;
        }

        Node* res = new Node(-1);
        auto walker = res;
        head = oriHead;
        int idxWalker = 0;
        while (1) {
            if (!head) break;

            Node* rand = head->random;

            walker->next = tmp[idxWalker];
            walker = walker->next;
            head = head->next;

            if (rand != nullptr) {
                int idxRand = rand->val;
                walker->random = tmp[idxRand];
            }

            idxWalker++;
        }

        return res->next;
    }
};