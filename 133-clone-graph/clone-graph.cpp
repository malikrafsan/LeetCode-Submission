/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* oldNode, map<Node*, Node*>& mp, set<Node*>& st) {
        if (st.find(oldNode) != st.end()) {
            return;
        }

        Node* newNode = new Node(oldNode->val);
        mp[oldNode] = newNode;
        st.insert(oldNode);
        vector<Node*> newNeighbors;
        for (auto nb: oldNode->neighbors) {
            if (mp.find(nb) == mp.end()) {
                dfs(nb, mp, st);
            }

            newNeighbors.push_back(mp[nb]);
        }
        newNode->neighbors = newNeighbors;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        set<Node*> st;
        map<Node*, Node*> mp;
        dfs(node, mp, st);
        return mp[node];
    }
};