class Solution {
    /*
    1. treat each token as either left open, a number to be add, or "+", "-"
    2. for each new number: collapse it with the top "*" or "/", then push it with correct sign
    3. for each right parenthesis, sum to the left into a number by summation, then treat it as a num in 2).
    4. sum the remainder stack
     */
    struct ent_t {
        bool isOp;
        bool isLeftOpen;
        bool isNum;
        
        char op;
        int val;
    };
    
    vector<ent_t> parse(const string &s) {
        vector<ent_t> ret;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] == '(') {
                ret.push_back(ent_t{false, true, false, 0, 0});
                i++;
            } else if (s[i] == ')') {
                ret.push_back(ent_t{false, false, false, 0, 0});
                i++;
            } else if (!isdigit(s[i])) {
                ret.push_back(ent_t{true, false, false, s[i], 0});
                i++;
            } else {
                int j = i;
                while (i < s.size() && isdigit(s[i])) {
                    i++;
                }
                
                ret.push_back(ent_t{false, false, true, 0, stoi(s.substr(j, i - j))});
            }
        }
        return ret;
    }
public:
    int calculate(string expr) {
        auto tokens = parse(expr);
        vector<ent_t> s;
        auto eval = [&](int num) {
            // clear all top level ops
           while (s.size() && s.back().isOp && (s.back().op == '*' || s.back().op == '/')) {
               char op = s.back().op; s.pop_back();
               int v1 = s.back().val; s.pop_back();
               if (op == '*') {
                   num = v1 * num;
               } else {
                   num = v1 / num;
               }
           }
            // push the result as a singleton with sign, no "+"
           if (s.empty() || s.back().isLeftOpen || s.back().isNum) {
               s.push_back(ent_t{false, false, true, 0, num});
           } else {
               assert(s.back().isOp);
               char op = s.back().op; s.pop_back();
               if (op == '-') {
                   s.push_back(ent_t{false, false, true, 0, 0-num});
               } else {
                   s.push_back(ent_t{false, false, true, 0, num});
               }
           }
        };
        auto sum = [&]() {
            int ret = 0;
            while (s.size() && !s.back().isLeftOpen) {
                ret += s.back().val; s.pop_back();
            }
            if (s.size()) {
                s.pop_back();
            }
            return ret;
        };
        for (auto t : tokens) {
            if (t.isNum) {
                eval(t.val);
            } else if (t.isOp || t.isLeftOpen) {
                s.push_back(t);
            } else {
                eval(sum());
            }
        }
        return sum();
    }
};