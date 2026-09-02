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
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> mp;
        return traverse(node, mp);
    }

    Node* traverse(Node* node, unordered_map<Node*, Node*>& mp) {
        Node* curr = new Node(node->val);
        mp[node] = curr;

        vector<Node*> res;
        for(int i = 0; i < node->neighbors.size(); i++) {
            if(mp.contains(node->neighbors[i])) {
                res.push_back(mp[node->neighbors[i]]);
            } else {
                res.push_back(traverse(node->neighbors[i], mp));
            }
        }
        curr->neighbors = res;
        return curr;
    }
};
