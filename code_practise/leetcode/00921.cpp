class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int more = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                left--;
                if (left < 0) {
                    more++;
                    left = 0;
                }
            }
        }
        return left + more;
    }
};