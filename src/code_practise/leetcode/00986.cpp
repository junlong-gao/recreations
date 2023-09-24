class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& A, vector<vector<int>>& B) {

        int i = 0; int j = 0;
        vector<vector<int>> ret;
        while (i < A.size() && j < B.size()) {
            if (A[i][1] < B[j][0]) {
                i++;
            } else if (B[j][1] < A[i][0]) {
                j++;
            } else {
                ret.push_back({
                                max(A[i][0], B[j][0]),
                                min(A[i][1], B[j][1])
                               });
                if (A[i][1] < B[j][1]) i++;
                else j++;
            }
        }
        
        return ret;
    }
};
