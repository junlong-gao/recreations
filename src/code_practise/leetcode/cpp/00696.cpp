class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0; int j = 0; int k = 0;
        int ret = 0;
        while (k <= s.size()) {
            while (k <= s.size()) {
                if (k > 0 && s[k] != s[k-1]) {
                    break;
                }
                k++;
            }
            ret += min(k-j, j-i);
            i = j;
            j = k;
            k++;
        }
        return ret;
    }
};