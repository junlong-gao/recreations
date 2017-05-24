/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) {
            return "";
        }
        
        string ret = to_string(root->val);
        ret += "[";
        for (auto c : root->children) {
            ret += serialize(c);
        } 
        ret += "]";
        return ret;
    }
	
    Node *parse(string &buf, int &idx) {
        if (idx == buf.size() || buf[idx] == ']') {
            return nullptr;
        }
        assert(isdigit(buf[idx]));
        int cur = idx;
        while (isdigit(buf[idx])) {
            idx++;
        }
        Node *ret = new Node{stoi(buf.substr(cur, idx - cur))};
        
        assert(idx < buf.size() && buf[idx] == '['); idx++;
        while (true) {
            Node *c = parse(buf, idx);
            if (c == nullptr) {
                break;
            } else {
                ret->children.push_back(c);
            }
        }
        assert(idx < buf.size() && buf[idx] == ']'); idx++;
        return ret;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int idx = 0;
        return parse(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));