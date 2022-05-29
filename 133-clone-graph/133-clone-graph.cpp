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
        if (!node) {
            return NULL;
        }
        unordered_map<Node*,Node*> map;
        return clone(node,map);
    }
    Node* clone(Node* node, unordered_map<Node*,Node*>& map) {
        Node* newNode = new Node(node->val);
        map[node] = newNode;
        vector<Node*> newNeighbors;
        for (Node* n: node->neighbors) {
            if (map.find(n) != map.end()) {
                newNeighbors.push_back(map[n]);
            } else {
                newNeighbors.push_back(clone(n,map));
            }
        }
        newNode->neighbors = newNeighbors;
        return newNode;
    }
};