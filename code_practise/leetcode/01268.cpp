class Solution {
    struct Trie {
        vector<Trie *> children{26, nullptr};  
        bool isWord{false};
    } root;
    
    void addWord(const string &s, int sofar, Trie *t) {
        if (sofar == s.size()) {
            t->isWord = true;
            return;
        }
        int c = s[sofar] - 'a';
        if (t->children[c] == nullptr) {
            t->children[c] = new Trie;
        }
        addWord(s, sofar + 1, t->children[c]);
    }
    void find3(Trie *t, string &pfx, vector<string> &out) {
        if (t == nullptr) {
            return;
        }
        if (out.size() == 3) {
            return;
        }
        
        if (t->isWord) {
            out.push_back(pfx);
        } // keep finding
        
        for (int i = 0; i < 26; ++i) {
            pfx.push_back('a' + i);
            find3(t->children[i], pfx, out);
            pfx.pop_back();
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (auto &p : products) {
            addWord(p, 0, &root);
        }
        
        vector<vector<string>> ret;
        string pfx;
        Trie *probe = &root;
        for (int i = 0; i < searchWord.size(); ++i) {
            pfx.push_back(searchWord[i]);
            if (probe) {
                probe = probe->children[pfx.back() - 'a'];
            }
            
            ret.emplace_back();
            find3(probe, pfx, ret.back());
        }
        
        return ret;
    }
};