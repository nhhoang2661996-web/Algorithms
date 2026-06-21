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
        if (node == nullptr) return nullptr;
        unordered_map<int, Node*> visited;
        queue<Node*> q;
        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for (Node* ner : cur->neighbors) {
                if(visited[ner->val] == nullptr){
                    Node* newNer = new Node(ner->val);
                    visited[ner->val] = newNer;
                    q.push(ner);
                }
                visited[cur->val]->neighbors.push_back(visited[ner->val]);
            }
        }
        return clone;
    }
};