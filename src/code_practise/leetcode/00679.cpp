// only 3(not 2) possible operation orders for 4 oprands
class Solution {
    vector<vector<int>> oprands;
    vector<char> ops;
    const double delta = 1000 * std::numeric_limits<double>::epsilon(); // XXX test case 8 3 8 3
    
    void genOprands(vector<vector<int>> &out, vector<int> &sofar, deque<int> cards) {
        if (cards.empty()) {
            out.push_back(sofar);
            return;
        }
        
        for (int i = 0; i < cards.size(); ++i) {
            sofar.push_back(cards.front());
            cards.pop_front();
            genOprands(out, sofar, cards);
            cards.push_back(sofar.back());
            sofar.pop_back();
        }
    }
    
    struct Node {
        bool isOp;
        char op;
        int val;
    };
    
    bool eval(const vector<Node> &suffix) {
        vector<double> s;
        for (auto &token : suffix) {
            if (token.isOp) {
                assert(s.size() > 1);
                double v2 = s.back(); s.pop_back();
                double v1 = s.back(); s.pop_back();
                switch (token.op) {
                    case '+': {s.push_back(v1 + v2); break;}
                    case '-': {s.push_back(v1 - v2); break;}
                    case '*': {s.push_back(v1 * v2); break;}
                    case '/': {s.push_back(v1 / v2); break;}
                    default: {assert(0);}
                }
            } else {
                s.push_back(1.0 * token.val);
            }
        }
        
        return std::abs(s.back() - 24.0) <= delta ;        
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<vector<int>> oprands;
        vector<vector<char>> ops;
        
        {
            vector<int> sofar;
            deque<int> q;
            for (auto c : cards) {
                q.push_back(c);
            }
            genOprands(oprands, sofar, q);
        }
        
        {
            vector<char> total {'+', '-', '*', '/'};
                
            for (auto c1 : total) {
                for (auto c2: total) {
                    for (auto c3 : total) {
                        ops.push_back({c1, c2, c3});
                    }
                }
            }
        }
        
        for (auto & vs: oprands) {
            for (auto & op : ops) {
                if (eval({
                       Node {false, 0, vs[0]}, 
                       Node {false, 0, vs[1]}, 
                       Node {true, op[0] }, 
                       Node {false, 0, vs[2]}, 
                       Node {false, 0, vs[3]}, 
                       Node {true, op[1]}, 
                       Node {true, op[2]} 
                       }) ||
                    eval({
                       Node {false, 0, vs[0]}, 
                       Node {false, 0, vs[1]}, 
                       Node {true, op[0]}, 
                       Node {false, 0, vs[2]}, 
                       Node {true, op[1]}, 
                       Node {false, 0, vs[3]}, 
                       Node {true, op[2]} 
                       }) ||
                    eval({
                       Node {false, 0, vs[0]}, 
                       Node {false, 0, vs[1]}, 
                       Node {false, 0, vs[2]},
                       Node {false, 0, vs[3]}, 
                       Node {true, op[0]}, 
                       Node {true, op[1]},
                       Node {true, op[2]} 
                       })) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
