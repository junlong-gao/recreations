class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0; int hi = 0; // #left - #right range
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                hi++; lo++;
            } else if (s[i] == '*') {
                lo--; hi++;
            } else {
               lo--; hi--; 
            }
            
            lo = max(lo, 0);
            if (hi < 0) {
                return false;
            }
        }
        return lo==0;
    }
};