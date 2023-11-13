/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

/*
  This is find intersection of linked list: old trick by going from the tail and to head in cycle at the same speed, they eventually will meet
 */
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *pr = p, *qr = q;
        while (p != q) {
            p = (p->parent == nullptr)? pr : p->parent;
            q = (q->parent == nullptr)? qr : q->parent;
        }
        return p;
    }
};