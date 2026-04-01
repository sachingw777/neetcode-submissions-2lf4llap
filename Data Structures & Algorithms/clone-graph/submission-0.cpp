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
        map<Node*, Node*> mp;
        return dfs(node, mp);
    }

    Node* dfs(Node* node, map<Node*, Node*>& mp){
        if(node == NULL) return NULL;

        if(mp.count(node)) return mp[node];

        Node* copyNode = new Node(node->val);
        mp[node] = copyNode;

        for(Node* nodeEl: node->neighbors){
            Node* small = dfs(nodeEl, mp);
            copyNode->neighbors.push_back(small);
        }

        return copyNode;
    }
};
