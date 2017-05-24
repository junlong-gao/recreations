class Solution {
    void search(int left, const int n, vector<string> *out, string &sofar) {
        if (sofar.length() == 2 * n) {
            out->push_back(sofar);
        } else {
            if (left < n) {
                sofar.push_back('(');
                search(left + 1, n, out, sofar);
                sofar.pop_back();
            }
            if (left > sofar.length() - left) {
                sofar.push_back(')');
                search(left, n, out, sofar);
                sofar.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
       vector<string> ret; 
       string tmp;
       search(0, n, &ret, tmp);
       return ret;
    }
};
